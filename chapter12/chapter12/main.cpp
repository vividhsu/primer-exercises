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
#include <fstream>
#include <set>
#include <map>
#include <sstream>

#include "strBlob.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_strBlob.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::ifstream;
using std::allocator;
using std::set;
using std::map;
using std::istringstream;

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

/**
 void process(shared_ptr<int> ptr){
    // use ptr
 }
*/

void ex12_10(){
    cout << "-----ex12.10-----" << endl;
    /**
     shared_ptr<int> p (new int(42));
     process(shared_ptr<int> (p));
    */
    cout << "when we call process, it creates a temporary smart pointer points where p points. p count is 2, after process finishes, p count decrements to 1. It's correct." << endl;
}

void ex12_11(){
    cout << "-----ex12.11-----" << endl;
    /**
     shared_ptr<int> p (new int(42));
     process(shared_ptr<int>(p.get()));
    */
    cout << "when we call process, it creates a temporary smart pointer, name it as q points where p points. but p and q are two separate smarter pointers. both count are 1. After process finishes, q count decrements to 0, free the memory. p becomes a dangling pointer. It's not correct." << endl;
}

void ex12_12(){
    cout << "-----ex12.12-----" << endl;
    /**
     auto p = new int();
     auto sp = make_shared<int>();
     (a) process(sp);
     (b) process(new int());
     (c) process(p);
     (d) process(shared_ptr<int>(p));
    */
    cout << "(a)(d)legal; (b)(c)illegal, smart pointers construct is explicit, can't convert plain pointer.  " << endl;
}

void ex12_13(){
    cout << "-----ex12.13-----" << endl;
    /**
     auto sp = make_shared<int>();
     auto p = sp.get();
     delete p;
    */
    cout << "sp becomes a dangling pointer because compile free the memory where p points, which also is where sp points." << endl;
}

void ex12_16(){
    cout << "-----ex12.16-----" << endl;
    unique_ptr<int> up1(new int(12));
//    unique_ptr<int> up2 = up1;
    cout << "error msg: call to implicitly-deleted copy constructor of \"unique_ptr<int>\" " << endl;
}

void ex12_17(){
    cout << "-----ex12.17-----" << endl;
    /**
     int ix = 1024, *pi = &ix, *pi2 = new int(2048);
     typedef unique_ptr<int> IntP;
     (a) IntP p0(ix);
     (b) IntP p1(pi);
     (c) IntP p2(pi2);
     (d) IntP p3(&ix);
     (e) IntP p4(new int(2048));
     (f) IntP p5(p2.get());
    */
    cout << "(c) (e): legal; (a) (b) (d): illegal, unique_ptr should points to dynamic memory; (f): legal but not safe: if other smart pointers point to the same memory, may cause dangling pointer if either free the memory." << endl;
}

void ex12_18(){
    cout << "-----ex12.18-----" << endl;
    cout << "shared_ptr may have more than one smart pointers point to the same memory. if we release the memory to another shared_ptr, we still have other shared_ptr point to the memory. " << endl;
}

void ex12_19(){
    cout << "-----ex12.19-----" << endl;
}

void ex12_20(const char* title){
    cout << "-----ex12.20-----" << endl;
    ifstream input(title);
    string line;
    strBlob blob;
    while (getline(input, line)){
        blob.push_back(line);
    }
    for (strBlobPtr pbeg(blob.begin()), pend(blob.end()); neq(pbeg, pend); pbeg.incr()) {
        cout << pbeg.deref() << " ";
    }
    cout << endl;
    input.close();
}

void ex12_21(){
    cout << "-----ex12.21-----" << endl;
    /**
     string& deref() const {
         return (*check(curr, "dereference past end"))[curr];
     }
    */
    cout << "original one is better, because if check returns a null pointer, we could not do subscript operation to what it points" << endl;
}

void ex12_23(){
    //refer to https://github.com/Mooophy/Cpp-Primer/blob/master/ch12/ex12_23.cpp
    cout << "-----ex12.23-----" << endl;
    char* combo = new char[255]();
    strcat(combo, "aaaa");
    strcat(combo, "bbbb");
    cout << combo << endl;
    delete [] combo;
    
    string a = "aaaa";
    string b = "bbbb";
    cout << a + b << endl;
}

void ex12_24(){
    cout << "-----ex12.24-----" << endl;
    string input;
    cin >> input;
    unique_ptr<char []> ua(new char[input.size()]);
    for(size_t i = 0 ; i < input.size(); i++){
        ua[i] = input[i];
    }
    
    ua.release();
}

void ex12_25(){
    cout << "-----ex12.25-----" << endl;
    int *pa = new int[10];
    delete [] pa;
}

void ex12_26(){
    cout << "-----ex12.26-----" << endl;
    int n = 20;
    allocator<string> alloc;
    auto p = alloc.allocate(n);
    auto q = p;
    string s;
    while (cin >> s && q != p + n) {
        alloc.construct(q++, s);
    }
    while (q != p) {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);
}

void ex12_27(){
    cout << "-----ex12.27-----" << endl;
}

void ex12_28(const char* title){
    cout << "-----ex12.28-----" << endl;
    ifstream input(title);
    vector<string> v;
    string line;
    while (getline(input, line)){
        v.push_back(line);
    }
    
    
    map<string, set<int>> m;
    for (int i = 0; i < v.size(); i++) {
        istringstream is(v[i]);
        string word;
        while (is >> word){
            if (m.find(word) == m.end()) {
                set<int> temp = {i};
                m.insert(std::pair<string, set<int>>(word,temp));
            }
            else{
                m[word].insert(i);
            }
        }
    }
    
    for (auto &i: m){
        cout << i.first << " occurs at line ";
        for (auto &j: i.second){
            cout << j << " ";
        }
        cout <<"\n";
    }
    cout << endl;
    
    input.close();
}

void ex12_29(){
    cout << "-----ex12.29-----" << endl;
    /**
    void runQueries(ifstream &infile){
        TextQuery tq(infile);
        while (true) {
            cout << "enter word to look for, or q to quit: ";
            string s;
            if (!(cin >> s) || s == "q")
                break;
            
            print(cout, tq.query(s)) << endl;
        }
    }
    */
    
    /**
    void runQueries(ifstream &infile){
        TextQuery tq(infile);
        string s;
        do {
            cout << "enter word to look for, or q to quit: ";
            string s;
            if (!(cin >> s) || s == "q")
                break;
    
            print(cout, tq.query(s)) << endl;
        } while (true);
        
    }
    */
    
}

void runQueries(ifstream &infile){
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        
        print(cout, tq.query(s)) << endl;
    }
}

void ex12_30(const char* title){
    cout << "-----ex12.30-----" << endl;
    ifstream input(title);
    runQueries(input);
    input.close();
}

void ex12_31(){
    cout << "-----ex12.31-----" << endl;
    cout << "if we use vector instead of set, we have to remove the duplicates first." << endl;
}

void runQueries_strBlob(ifstream &infile){
    TextQuery_strBlob tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        
        QueryResult_strBlob tq_result = tq.query(s);
        print_strBlob(cout, tq_result) << endl;
    }
}

void ex12_32(const char* title){
    cout << "-----ex12.32-----" << endl;
    ifstream input(title);
    runQueries_strBlob(input);
    input.close();
}


void ex12_33(){
    cout << "-----ex12.33-----" << endl;
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
//    ex12_10();
//    ex12_11();
//    ex12_12();
//    ex12_13();
//    ex12_16();
//    ex12_17();
//    ex12_18();
//    ex12_20(argv[1]);
//    ex12_21();
//    ex12_23();
//    ex12_24();
//    ex12_25();
//    ex12_27();
//    ex12_28(argv[2]);
//    ex12_29();
//    ex12_30(argv[2]);
//    ex12_31();
//    ex12_32(argv[2]);
//    ex12_33();
    return 0;
}
