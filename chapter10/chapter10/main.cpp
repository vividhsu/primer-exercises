//
//  main.cpp
//  chapter10
//
//  Created by vividhsu on 5/14/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <iterator>
#include <fstream>
#include <sstream>
#include "Sales_data.h"

using std::vector;
using std::list;
using std::string;
using std::deque;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::ifstream;
using std::istringstream;

void ex10_1(){
    cout << "-----ex10.1-----" << endl;
    vector<int> a = {10, 45, 56, 78, 10, 34, 23, 10, 10};
    auto cnt = count(a.begin(), a.end(), 10);
    cout << "how many 10 in the vector: " << cnt << endl;
}

void ex10_2(){
    cout << "-----ex10.2-----" << endl;
    list<string> a = {"a", "the", "a", "other", "another", "a"};
    auto cnt = count(a.begin(), a.end(), "a");
    cout << "how many \"a\" in the list: " << cnt << endl;
}

void ex10_3(){
    cout << "-----ex10.3-----" << endl;
    vector<int> a = {1, 3, 5, 7, 9};
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << "Sum of vector: " << sum << endl;
}

void ex10_4(){
    cout << "-----ex10.4-----" << endl;
    vector<double> a = {1.2, 3.4, 5.6, 7.8, 9.2};
    double sum = accumulate(a.cbegin(), a.cend(), 0);
    cout << "Sum of vector: " << sum << endl;
    cout << "loss of precision: \n"
         << "because accumulate declares as\n"
         << "template <class InputIterator, class T> T accumulate (InputIterator first, InputIterator last, T init);\n"
         << "when pass 0 to third parameter, compiler deduces the initial value is int."
         <<endl;
}

void ex10_5(){
    cout << "-----ex10.5-----" << endl;
    const char a[3][4] = {"thr", "tho", "the"};
    const char b[3][4] = {"thr", "tho", "the"};
    vector<const char*> va (std::begin(a), std::end(a));
    vector<const char*> vb (std::begin(b), std::end(b));
    bool isSame = equal(va.cbegin(), va.cend(), vb.cbegin());
    cout << "a and b are same: " << isSame << endl;
    cout << "C-style comparison is diff. than string.\n"
         << "because C-style strings compare the pointer value (address)\n"
         << "not the strings themselves."
         <<endl;
}

void ex10_6(){
    cout << "-----ex10.6-----" << endl;
    deque<int> a;
    fill_n(back_inserter(a), 10, 0);
    cout << "print deque:";
    for (auto iter = a.begin(); iter != a.end(); iter++){
        cout << " " << *iter;
    }
    cout << endl;
}

void ex10_7(){
    cout << "-----ex10.7-----" << endl;
    cout << "(a): vec is empty, copy lst to vec will make vec undefined.\n";
    cout << "change vec.begin() to back_inserter(vec)" << endl;
    vector<int> vec;
    list<int> lst;
    int i;
    while(cin >> i)
        lst.push_back(i);
    copy(lst.begin(), lst.end(), back_inserter(vec));
    for (auto iter = vec.begin(); iter != vec.end(); iter++){
        cout << " " << *iter;
    }
    cout << endl;
    
    cout << "(b): reserve only allocate the memory for vec, but vec's size is still empty.\n";
    cout << "change vec.reserve(10) to vec.resize(10) "<< endl;
    vector<int> vec2;
    vec2.resize(10);
    fill_n(vec2.begin(), 10, 0);
    for (auto iter = vec2.begin(); iter != vec2.end(); iter++){
        cout << " " << *iter;
    }
    cout << endl;
    
}

void ex10_8(){
    cout << "-----ex10.8-----" << endl;
    cout << "back_inserter which is a container operation changes the size of the container.\n";
    cout << "algorithm operations don't change the size of the container." << endl;
}

ostream& printVec(ostream &os, const vector<string> &words){
    for(auto &word: words){
        os << word << " ";
    }
    return os;
}

void elimDups(vector<string> &words){
//    printVec(cout, words) << endl;
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words. end());
//    printVec(cout, words) << endl;
    words.erase(end_unique, words.end());
//    printVec(cout, words) << endl;
}

void ex10_9(const char* title){
    cout << "-----ex10.9-----" << endl;
    ifstream input(title);
    vector<string> a;
    string b;
    while(input >> b){
        a.push_back(b);
    }
    elimDups(a);
    input.close();
    cout << "refer to https://github.com/Mooophy/Cpp-Primer/blob/master/ch10/ex10_09.cpp." << endl;
}

void ex10_10(){
    cout << "-----ex10.10-----" << endl;
    cout << "algorithms like sort and unique don't change the size of the contaier.\n";
    cout << "member functions like erase change the size." << endl;
}

bool isShorter(const string &s1, const string &s2){
    return (s1.size() < s2.size());
}

void ex10_11(const char* title){
    cout << "-----ex10.11-----" << endl;
    ifstream input(title);
    vector<string> a;
    string b;
    while(input >> b){
        a.push_back(b);
    }
    elimDups(a);
    stable_sort(a.begin(), a.end(), isShorter);
    printVec(cout, a) << endl;
    input.close();
}

bool compareIsbn(const Sales_data& item1, const Sales_data& item2){
    return (item1.isbn() < item2.isbn());
}

ostream& print(ostream& os, const Sales_data &item){
    os << item.isbn() << endl;
    return os;
}

void ex10_12(const char* title){
    cout << "-----ex10.12-----" << endl;
    ifstream input(title);
    string s;
    vector<Sales_data> v;
    while(getline(input, s)){
        istringstream line(s);
        Sales_data book;
        line >> book.bookNo;
        v.push_back(book);
    }
    sort(v.begin(), v.end(), compareIsbn);
    for(auto &vv: v)
        print(cout, vv);
    input.close();
}

bool isFiveChar(const string &s){
    return (s.size() >= 5);
}

void ex10_13(const char* title){
    cout << "-----ex10.13-----" << endl;
    ifstream input(title);
    vector<string> a;
    string b;
    while(input >> b){
        a.push_back(b);
    }
    partition(a.begin(), a.end(), isFiveChar);
    printVec(cout, a);
    input.close();
}

void ex10_14(){
    cout << "-----ex10.14-----" << endl;
    auto f = [] (int a, int b) { return a + b; };
    cout << f(34, 56) << endl;
}

void ex10_15(){
    cout << "-----ex10.15-----" << endl;
    int a = 50;
    auto f = [a] (int b) { return a + b; };
    cout << f(20) << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size();});
    auto iter = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz;});
    for_each(iter, words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;
}

void ex10_16(const char* title){
    cout << "-----ex10.16-----" << endl;
    ifstream input(title);
    vector<string> v;
    string s;
    while(input >> s){
        v.push_back(s);
    }
    biggies(v, 4);
    input.close();
}

void ex10_17(const char* title){
    cout << "-----ex10.17-----" << endl;
    ifstream input(title);
    vector<Sales_data> books;
    string s;
    while(getline(input, s)){
        Sales_data book(s);
        books.push_back(book);
    }
    sort(books.begin(), books.end(), [](const Sales_data& a, const Sales_data& b) {return a.isbn() < b.isbn();});
    for (auto &b: books){
        print(cout, b);
    }
}

void biggies2(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    auto iter = partition(words.begin(), words.end(), [sz](const string &a) {return a.size() < sz;});
    for_each(iter, words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;
}

void ex10_18(const char* title){
    cout << "-----ex10.18-----" << endl;
    ifstream input(title);
    vector<string> v;
    string s;
    while(input >> s){
        v.push_back(s);
    }
    biggies2(v, 4);
    input.close();
}

void biggies3(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    auto iter = stable_partition(words.begin(), words.end(), [sz](const string &a) {return a.size() < sz;});
    for_each(iter, words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;
}

void ex10_19(const char* title){
    cout << "-----ex10.19-----" << endl;
    ifstream input(title);
    vector<string> v;
    string s;
    while(input >> s){
        v.push_back(s);
    }
    biggies3(v, 4);
    input.close();
}


int main(int argc, const char * argv[]) {
//    ex10_1();
//    ex10_2();
//    ex10_3();
//    ex10_4();
//    ex10_5();
//    ex10_6();
//    ex10_7();
//    ex10_8();
//   ex10_9(argv[1]);
//    ex10_10();
//    ex10_11(argv[1]);
//    ex10_12(argv[2]);
//    ex10_13(argv[1]);
//    ex10_14();
//    ex10_15();
//    ex10_16(argv[1]);
//    ex10_17(argv[2]);
//    ex10_18(argv[1]);
    ex10_19(argv[1]);
    return 0;
}
