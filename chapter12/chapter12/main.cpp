//
//  main.cpp
//  chapter12
//
//  Created by vividhsu on 5/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

void ex12_1(){
    cout << "-----ex12.1-----" << endl;
    cout << "b2 is destroyed, but the elements in b2 don't.\n";
    cout << "b1 has 4 elements, b2 has 0." << endl;
}

void ex12_2(){
    cout << "-----ex12.2-----" << endl;
}

void ex12_3(){
    cout << "-----ex12.3-----" << endl;
    // https://isocpp.org/wiki/faq/const-correctness#const-member-fns
    // http://www.douban.com/group/topic/61573279/
    cout << "refer to https://github.com/Mooophy/Cpp-Primer/tree/master/ch12 " << endl;
}

void ex12_4(){
    cout << "-----ex12.4-----" << endl;
    cout << "we don't need to check if i is greater than 0 in function check because\n";
    cout << "i is unsigned, any less than 0 input will convert to greater than 0." << endl;
}

vector<int>* createDynamicVec(){
    vector<int> *vp = new vector<int>;
    return vp;
}

void readDynamicVec(vector<int>* pv){
    int i;
    cout << "Please enter integers: \n";
    while (cin >> i) {
        pv -> push_back(i);
    }
}

void printDynamicVec(vector<int>* pv){
    for (auto &v: *pv){
        cout << v << " ";
    }
    cout << endl;
}

void ex12_6(){
    cout << "-----ex12.6-----" << endl;
    vector<int>* pv = createDynamicVec();
    readDynamicVec(pv);
    printDynamicVec(pv);
    delete pv;
}

shared_ptr<vector<int>> createSmarterPointerVec(){
    shared_ptr<vector<int>> sv = make_shared<vector<int>>();
    return sv;
}

void readSmarterPointerVec(shared_ptr<vector<int>> sv){
    int i;
    cout << "Please enter integers: \n";
    while (cin >> i) {
        sv -> push_back(i);
    }
}

void printSmartPointerVec(shared_ptr<vector<int>> sv){
    for (auto &v: *sv){
        cout << v << " ";
    }
    cout << endl;
}

void ex12_7(){
    cout << "-----ex12.7-----" << endl;
    shared_ptr<vector<int>> sv = createSmarterPointerVec();
    readSmarterPointerVec(sv);
    printSmartPointerVec(sv);
}

void ex12_8(){
    cout << "-----ex12.8-----" << endl;
    /**
    bool b(){
        int* p = new int;
        //...
        return p;
    */
    cout << "memory leak will happen because when \"return p\" executes, p converts to boolean, we can't free the momery which p points." << endl;
}

void ex12_9(){
    cout << "-----ex12.9-----" << endl;
    /**
    int *q = new int(42), *r = new int(100);
    r = q;
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    r2 = q2;
    */
    cout << "with built-in pointers, when \"r = q\" executes, the memory r points has no access, memory leak will happen.\n";
    cout << "with smart pointer, compiler will automatically free the memory." <<endl;
}

int main(int argc, const char * argv[]) {
//    ex12_1();
//    ex12_2();
//    ex12_3();
//    ex12_4();
//    ex12_6();
//    ex12_7();
//    ex12_8();
//    ex12_9();
    return 0;
}
