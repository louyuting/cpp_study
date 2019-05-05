//
// Created by Yuting Lou on 2019-05-05.
//
#include "../common_basic.h"
#include <memory>
#include <thread>

template <typename T>
class lockfree_stack
{
private:
    struct node
    {
        shared_ptr<T> data;
        node* next;

        node(T const& data_):data(std::make_shared<T>(data_))
        {}
    };
    std::atomic<node*> head;

public:
    lockfree_stack()
    {
        head.store(nullptr);
    }

    void push(T const& data)
    {
        node* const new_node = new node(data);
        new_node->next = head.load();
        while (!head.compare_exchange_weak(new_node->next, new_node));
    }

    shared_ptr<T> pop()
    {
        //这里先获取head节点的地址
        node* old_head = this->head.load();
        // 然后更新先前old_head的地址到old_head的下一个节点; 如果head节点已经被别的线程改变了；
        // 那么此时head的值就不等于old_head， 那么compare_exchange_weak会自动更新old_head为最新的head,并返回false，然后重复
        // 直到old_head 和 head一致
        while (old_head && !this->head.compare_exchange_weak(old_head, old_head->next));
        return old_head ? old_head->data : std::shared_ptr<T>();
    }

    bool empty()
    {
        return head.load() == nullptr;
    }
};



void thread_func1(lockfree_stack<int>* stack)
{
    for (int i = 0; i < 1000; ++i)
    {
        stack->push(i);
    }
}

void thread_func2(lockfree_stack<int>* stack)
{
    for (int i = 1000; i < 2000; ++i)
    {
        stack->push(i);
    }
}

static atomic<int> cnt(0);
static atomic<int> cnt2{1};

void thread_func3(lockfree_stack<int>* stack)
{
    for (int i = 1000; i < 2000; ++i)
    {
        cnt.fetch_add(1);
        shared_ptr<int> rt = stack->pop();
        if (!rt){
            continue;
        }
        cout << *rt << endl;
    }
}

void lockfree_stack_normal_test1()
{
    auto* stack = new lockfree_stack<int>();
    thread t1(thread_func1, stack);
    thread t2(thread_func2, stack);
    thread t3(thread_func3, stack);
    thread t4(thread_func3, stack);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    delete stack;
    cout << "finish, stack is empty: "<< stack->empty() << endl;

    cout << "cnt: "<< cnt.load() << endl;
}



int main()
{
    cout << __FUNCTION__ << endl;
    cout << "/******************lockfree_stack_normal_test1()***********************/" << endl;
    lockfree_stack_normal_test1();
}






