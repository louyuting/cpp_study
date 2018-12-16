//
// Created by 娄宇庭 on 2018/12/14.
//

#ifndef DEMO_TEMPLATE_TEST_H
#define DEMO_TEMPLATE_TEST_H

template<typename valType>
class BTnode {
public:
    BTnode();
    BTnode(const valType &val);

    void insert_value(const valType& val);
//private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};

template<typename valType>
inline BTnode<valType>::
BTnode(const valType &val) : _val(val){
    this->_cnt = 1;
    this->_lchild = this->_rchild = 0;
}

template <typename valType>
void BTnode<valType>::
insert_value(const valType &val) {
    if(val == _val){
        this->_cnt++;
        return;
    }
    if( val < _val){
        if(!this->_lchild){
            _lchild = new BTnode(val);
        } else{
            _lchild->insert_value(val);
        }
    } else {
        if(!this->_rchild){
            _rchild = new BTnode(val);
        } else{
            _rchild->insert_value(val);
        }
    }
}




/**
 * Binary tree implement
 *
 * @tparam elemType
 */
template<typename elemType>
class BinaryTree {
public:
    BinaryTree();

    // copy constructor
    BinaryTree(const BinaryTree &binaryTree);

    ~BinaryTree();

    // 运算符assignment重载
    BinaryTree &operator=(const BinaryTree &binaryTree);

    bool empty() {
        return _root == 0;
    }

    void clear();
    void insert(const elemType& elem);
    void remove(const elemType &elem);

private:
    BTnode<elemType>* _root;
    // 将src指向的子树复制到tar指到子树
    void copy(BTnode<elemType> *tar, BTnode<elemType> *src);
};


template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree() : _root(0) {
    // 带初始化列表的构造器
}

template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree &binaryTree) {
    copy(_root, binaryTree._root);
}

template <typename elemType>
inline BinaryTree<elemType>::
~BinaryTree() {
    clear();
}

template <typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::
operator=(const BinaryTree &binaryTree) {
    if (this != &binaryTree){
        clear();
        copy(_root, binaryTree._root);
    }
    return *this;
}


template <typename elemType>
inline void
BinaryTree<elemType>::
insert(const elemType& elem){
    if(!_root){
        _root = new BTnode<elemType>(elem);
    } else {
        _root->insert_value(elem);
    }
}

template <typename elemType>
inline void
BinaryTree<elemType>::
remove(const elemType &elem) {
    if(!_root){
        return;
    }
    if( _root->_val == elem){
        //remove_root();//根节点的移除操作以特例处理
    } else {
        //_root->remove_value(elem, _root);
    }
}





#endif //DEMO_TEMPLATE_TEST_H
