//
//  main.cpp
//  chapter13
//
//  Created by vividhsu on 6/1/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include "HasPtr.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


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
    
}

void ex13_09(){
    cout << "-----ex13.9-----" << endl;
    cout << "destructor is a special member function that cleans up an object when the object goes out of scope or is deleted. \n";
    cout << "destructors work: (1) variables are destroyed when they go out of scope; (2) members of an object are destroyed when the object of which they are a part is destroyed; (3) elements in a container - whether a library container or an array - are destroyed when the container is destroyed; (4) dynamically allocated objects are destroyed when the delete operator is applied to a pointer to the object; (5) temporary objects are destroyed at the end of the full expression in which the tmporary was created. \n";
    cout << "compiler generates synthesized destructor when class does not define one." << endl;
}

void ex13_11(){
    cout << "-----ex13.11-----" << endl;
}

void ex13_12(){
    cout << "-----ex13.12-----" << endl;
    /**
    bool fcn(const Sales_data *trans, Sales_data accum){
        Sales_data item1(*trans);
        Sales_data item2(accum);
        return item1.isbn() != item2.isbn();
    } //item1, item2 out of scope, call destructor
     //accum is a temporary variable, when function finishes, call destructor
    */
}

struct X {
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    X& operator=(const X &) { cout << "X& operator=(const X &)" << endl; return *this; }
    ~X() { cout << "~X()" << endl; }
};

void f1(X a){
    cout << "......." << endl;
    X b = a;
    cout << "......." << endl;
}

void f2(X &a){
    cout << "......." << endl;
    X b = a;
    cout << "......." << endl;
}

void ex13_13(){
    cout << "-----ex13.13-----" << endl;
    cout << "dynamic allocate: \n";
    cout << "-------" << endl;
    X *a = new X();
    cout << "-------" << endl;
    delete a;
    cout << "pass nonreference: \n";
    cout << "-------" << endl;
    X b;
    cout << "-------" << endl;
    f1(b);
    cout << "pass reference: \n";
    cout << "-------" << endl;
    X *c = new X();
    cout << "-------" << endl;
    f2(*c);
    cout << "-------" << endl;
    delete c;
    cout << "put in container" << endl;
    cout << "-------" << endl;
    X d;
    cout << "-------" << endl;
    vector<X> dv;
    cout << "-------" << endl;
    dv.push_back(d);
    
    
}

int main(int argc, const char * argv[]) {
//    ex13_01();
//    ex13_02();
//    ex13_03();
//    ex13_05();
//    ex13_06();
//    ex13_08();
//    ex13_09();
//    ex13_11();
//    ex13_12();
    ex13_13();
    return 0;
}