//
//  main.cpp
//  chapter13
//
//  Created by vividhsu on 6/1/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


void ex13_01(){
    cout << "-----ex13.1-----" << endl;
    cout << "copy constructor is the constructor that initializes a new object as a copy of another object of the same type.\n";
    cout << "it is used (1) define variables using an =; (2) pass an object as an argument to a parameter of nonreference type; (3) return an object from a function that has a nonreference return type; (3) brace initialize the elements in an array or the members of an aggregate class." << endl;
    
}

void ex13_02(){
    cout << "-----ex13.2-----" << endl;
    // Sales_data::Sales_data(Sales_data rhs);
    cout << "since rhs is nonreference parameter, the call would never succeed - to call the copy constructor, we'd need to use the copy constructor to the argument, but to copy the argument, we'd need to call the copy constructor, and so on indefinitely." << endl;
    
}

void ex13_03(){
    cout << "-----ex13.3-----" << endl;
    cout << "copy a strBlob will increase the count of shared_ptr. copy a strBlobPtr wouldn't increase the count of weak_ptr." << endl;
    
}


void ex13_05(){
    cout << "-----ex13.5-----" << endl;
    /**
    class HasPtr {
    public:
        HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
        HasPtr(const HasPtr &orig): ps(orig.ps), i(orig.i) {}
    private:
        string *ps;
        int i;
    };
    */
}

void ex13_06(){
    cout << "-----ex13.6-----" << endl;
    cout <<"copy-assignment operator is the version of assignment operator that takes an object of the same type as its type.\n";
    cout << "it is used to assign the same type object to another. \n";
    cout << "synthesized copy-assignment operator assignes each nonstatic member of the right-hand to the left-hand using the copy-assignment operator for the type of the member.\n";
    cout << "compiler generates a synthesized copy-assignment operator if the class does not define one." <<endl;
}

void ex13_08(){
    // refer to https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_08.h
    cout << "-----ex13.8-----" << endl;
    /**
    class HasPtr {
    public:
        HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
        HasPtr(const HasPtr &orig): ps(orig.ps), i(orig.i) {}
        HasPtr& operator=(const HasPtr &rhs){
            string *temp = new string(*rhs.ps);
            delete ps;
            ps = temp;
            i = rhs.i;
            return *this;
        }
    private:
        string *ps;
        int i;
    };
    */
}

int main(int argc, const char * argv[]) {
    ex13_01();
    ex13_02();
    ex13_03();
    ex13_05();
    ex13_06();
    ex13_08();
    return 0;
}
