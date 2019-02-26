//
// Created by 娄宇庭 on 2018/10/31.
//

#ifndef DEMO_LIBMAT_H
#define DEMO_LIBMAT_H

#include <iostream>
#include <string>

using namespace std;

class LibMat{

public:
    LibMat(){
        cout<< "LibMat::LibMat() default constructor!" << endl;
    }

    virtual ~LibMat(){
        cout<< "LibMat::~LibMat() destructor!" << endl;
    }

    virtual void print() const {
        cout<< "LibMat::print() -- i am a LibMat object!" << endl;
    }
};

class Book : public LibMat {
public:
    Book(const string &title, const string &author)
        : _title(title), _author(author){
        cout << "Book::Book(), title=" << this->_title <<", author="
        << this->_author << endl;
    }

    virtual ~Book(){
        cout << "Book::~Book(), destructor!" << endl;
    }

    virtual void print() const {
        cout << "  Book::print() -- I am a Book object" << endl
        << "  my title is :" << this->_title << endl
        << "  my author is ：" << this->_author << endl;
    }

    const string& title() const {
        return this->_title;
    }

    const string& author() const {
        return this->_author;
    }


protected:
    string _title;
    string _author;
};


class AudioBook : public Book{

public:
    AudioBook(const string &title, const string &author, const string &narrator)
    : Book(title, author), _narrator(narrator)
    {
        cout<< "AudioBook::AudioBook(), title=" << this->_title <<", author="
            << this->_author << ", narrator="<< this->_narrator << endl;
    }

    ~AudioBook(){
        cout<< "AudioBook::~AudioBook() destructor!" << endl;
    }

    virtual void print() const
    {
        cout << "  AudioBook::print() -- I am a AudioBook object" << endl
             << "  my title is :" << this->_title << endl
             << "  my author is ：" << this->_author << endl
             << "  my narrator is ：" << this->_narrator << endl;
    }

    const string& narrator() const {
        return this->_narrator;
    }
protected:
    string _narrator;
};



void print(const LibMat &mat){
    cout << "in global print(): about to print mat.print()\n";
    mat.print();
}

#endif //DEMO_LIBMAT_H
