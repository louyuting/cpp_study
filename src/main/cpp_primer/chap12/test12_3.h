//
// Created by 娄宇庭 on 2018/12/18.
//

#ifndef DEMO_TEST12_3_H
#define DEMO_TEST12_3_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

class QueryResult;

typedef vector<string>::size_type line_no;

class TextQuery{
public:
    explicit TextQuery(istream& is);
    QueryResult query(const string& s) const ;
private:
    //输入文件，每一行以一个String保存
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(istream &is): file(new vector<string>) {
    string text;
    while ( getline(is, text) ){
        this->file->push_back(text);
        // 当前行号
        int n = (int)(this->file->size()-1);
        istringstream line(text);
        string word;
        while (line >> word) {// 对行中每个单词
            // lines是一个 shared_ptr
            auto &lines = this->wm[word];
            if(!lines){//当我们第一次遇到这个单词时，lines为空
                lines.reset(new set<line_no>);
            }
            // 将行号插入set
            lines->insert(n);
        }

    }
}

class QueryResult {
    friend ostream& print(ostream& os, const QueryResult& qr);
public:
    QueryResult() = default;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
            :sought(s), lines(p), file(f){}
private:
    string sought;
    // 出现的行号
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sou) const {
    static shared_ptr<set<line_no >> nodata(new set<line_no >);
    auto loc = this->wm.find(sou);
    if (loc == this->wm.end()){
        return QueryResult(sou, nodata, this->file);
    } else{
        return QueryResult(sou, loc->second, this->file);
    }
}





ostream& print(ostream& os, const QueryResult& qr){
    os << qr.sought << " occurs " << qr.lines->size() <<
    " times" << endl;
    for(auto num : *qr.lines) {
        os << "\t（line" << num +1 << "）" << *(qr.file->begin() + num)
        << endl;
    }
    return os;
}


void runQueries(istream& is){
    // infile指向我们要处理的文件

    // 保存文件并建立查询map
    TextQuery tq(is);

    //与用户交互，输入并打印结果
    while (true) {
        cout << "input query word:" << endl;
        string str;
        if ( !(cin >> str) || str == "q"){
            break;
        }

        // 指向查询并打印结果
        print(cout, tq.query(str));
    }

}






















#endif //DEMO_TEST12_3_H
