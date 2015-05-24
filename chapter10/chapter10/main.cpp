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
#include <functional>
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
using std::ofstream;
using std::istringstream;
using std::istream_iterator;
using std::ostream_iterator;
using namespace std::placeholders;


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
    auto f = [a] (int b) { return a + b; }; // f stored a copy of a when we create it
    a = 80; // a changed wont affect f
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

void ex10_20(const char* title){
    cout << "-----ex10.20-----" << endl;
    ifstream input(title);
    vector<string> v;
    string s;
    while(input >> s){
        v.push_back(s);
    }
    auto cnt = count_if(v.begin(), v.end(), [] (const string &a) { return a.size() >= 6;});
    cout << cnt << endl;
    input.close();
}

void ex10_21(){
    cout << "-----ex10.21-----" << endl;
    //refer to https://github.com/Mooophy/Cpp-Primer/blob/master/ch10/ex10_20_21.cpp
    int num = 3;
    auto f = [&num] () -> bool {if(num == 0) {return true;} else {--num; return false;}};
    while (!f()){
        cout << num << " ";
    }
    cout << num << endl;
}

bool check_size(const string& s, string::size_type sz){
    return s.size() >= sz;
}

void ex10_22(const char* title){
    cout << "-----ex10.22-----" << endl;
    ifstream input(title);
    vector<string> v;
    string s;
    while(input >> s){
        v.push_back(s);
    }
    auto cnt = count_if(v.begin(), v.end(), bind(check_size, _1, 6));
    cout << cnt << endl;
    input.close();
}

void ex10_23(){
    //refer to https://github.com/Mooophy/Cpp-Primer/tree/master/ch10
    cout << "-----ex10.23-----" << endl;
    cout << "assume the old callable object has n parameters, then bind takes (n+1) arguments." << endl;
}

bool check_size2(const string &s, int i){
    return s.size() < i;
}

void ex10_24(){
    cout << "-----ex10.24-----" << endl;
    vector<int> iv = {1,2,3,4,5,6,7};
    string s = "abc";
    auto iter = find_if(iv.cbegin(), iv.cend(), bind(check_size2, s, _1));
    cout << *iter << endl;
}

void biggies4(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    auto iter = partition(words.begin(), words.end(), bind(check_size2, _1, sz));
    for_each(iter, words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;
}

void ex10_25(const char* title){
    cout << "-----ex10.25-----" << endl;
    ifstream input(title);
    vector<string> v;
    string s;
    while(input >> s){
        v.push_back(s);
    }
    biggies4(v, 4);
    input.close();
}

void ex10_26(){
    cout << "-----ex10.26-----" << endl;
    cout << "back_inserter creates an iterator that uses push_back\n";
    cout << "front_inserter creates an iterator that uses push_front\n";
    cout << "inserter creates an iterator that uses insert" << endl;
}

void ex10_27(){
    cout << "-----ex10.27-----" << endl;
    vector<int> a = {1,2,2,4,6,6,1};
    list<int> b;
    unique_copy(a.begin(), a.end(), back_inserter(b));
    for(auto iter = b.begin(); iter != b.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

void ex10_28(){
    cout << "-----ex10.28-----" << endl;
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    cout << "vector a: ";
    for(auto iter = a.begin(); iter != a.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    vector<int> b;
    copy(a.begin(), a.end(), inserter(b, b.begin()));
    cout << "vector b: ";
    for(auto iter = b.begin(); iter != b.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    list<int> c;
    copy(a.begin(), a.end(), back_inserter(c));
    cout << "list c: ";
    for(auto iter = c.begin(); iter != c.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    deque<int> d;
    copy(a.begin(), a.end(), front_inserter(d));
    cout << "deque d: ";
    for(auto iter = d.begin(); iter != d.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

void ex10_29(const char *title){
    cout << "-----ex10.29-----" << endl;
    ifstream in(title);
    istream_iterator<string> in_iter(in), eof;
    vector<string> vec(in_iter, eof);
    printVec(cout, vec);
    in.close();
}

void ex10_30(){
    cout << "-----ex10.30-----" << endl;
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    sort(vec.begin(), vec.end());
    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
}

void ex10_31(){
    cout << "-----ex10.31-----" << endl;
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    sort(vec.begin(), vec.end());
    ostream_iterator<int> out_iter(cout, " ");
    unique_copy(vec.begin(), vec.end(), out_iter);
}

void ex10_33(const char *in, const char *out_odd, const char *out_even){
    cout << "-----ex10.33-----" << endl;
    ifstream input(in);
    ofstream output_odd(out_odd);
    ofstream output_even(out_even);
    istream_iterator<int> in_iter(input), eof;
    ostream_iterator<int> out_iter_odd(output_odd, " ");
    ostream_iterator<int> out_iter_even(output_even, "\n");
    vector<int> vec(in_iter, eof);
    for(auto iter = vec.begin(); iter != vec.end(); iter++){
        if((*iter) % 2 != 0){
            *out_iter_odd++ = *iter;
        }
        else{
            *out_iter_even++ = *iter;
        }
    }
    
    input.close();
    output_odd.close();
    output_even.close();
}

void ex10_34(){
    cout << "-----ex10.34-----" << endl;
    vector<int> vec{1,2,3,4,5,6};
    for(auto rev_iter = vec.crbegin(); rev_iter != vec.crend(); rev_iter++)
        cout << *rev_iter << " ";
    cout << endl;
}

void ex10_35(){
    cout << "-----ex10.35-----" << endl;
    vector<int> vec{1,2,3,4,5,6};
    auto iter = vec.cend();
    do{
        --iter;
        cout << *iter << " ";
    }while (iter != vec.cbegin());
    cout << endl;
}

void ex10_36(){
    cout << "-----ex10.36-----" << endl;
    vector<int> vec{0,1,0,9,8,0,4};
    auto it = find(vec.crbegin(), vec.crend(), 0);
    cout<< &(*it) << endl;
    cout << &vec[0] << " " << &vec[2] <<" "<< &vec[5] << endl;
}

void ex10_37(){
    cout << "-----ex10.37-----" << endl;
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    list<int> lst;
    copy(vec.crbegin()+3, vec.crend()-2, inserter(lst,lst.begin()));
    for(auto iter = lst.begin(); iter != lst.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

void ex10_38(){
    cout << "-----ex10.38-----" << endl;
    cout << "input iterator: 1. equality and ineuqality operation(==, !=);\n";
    cout << "                2. prefix and postfix increment(++);\n";
    cout << "                3. dereference operation(*);\n";
    cout << "                4. arrow operation(->).\n";
    cout << "output iterator: 1. prefix and postfix increment(++);\n";
    cout << "                 2. dereference operation(*).\n";
    cout << "forward iterator: 1. equality and ineuqality operation(==, !=);\n";
    cout << "                  2. prefix and postfix increment(++);\n";
    cout << "                  3. dereference operation(*);\n";
    cout << "                  4. arrow operation(->).\n";
    cout << "                  5. read or write the same element mutiple times.\n";
    cout << "bidiretional iterator: 1. equality and ineuqality operation(==, !=);\n";
    cout << "                       2. prefix and postfix increment(++);\n";
    cout << "                       3. prefix and postfix decrement(++);\n";
    cout << "                       4. dereference operation(*);\n";
    cout << "                       5. arrow operation(->).\n";
    cout << "                       6. read or write the same element mutiple times.\n";
    cout << "random-access iterator: 1. equality and ineuqality operation(==, !=);\n";
    cout << "                        2. prefix and postfix increment(++);\n";
    cout << "                        3. prefix and postfix decrement(++);\n";
    cout << "                        4. dereference operation(*);\n";
    cout << "                        5. arrow operation(->).\n";
    cout << "                        6. read or write the same element mutiple times;\n";
    cout << "                        7. relational opreation(<, <=, >, >=);\n";
    cout << "                        8. addition and subtraction opeation (+, +=, -, -=);\n";
    cout << "                        9. subtration(-) applied to two iterators;\n";
    cout << "                        10. subscript operation(iter[n]).";
    cout << endl;
}

void ex10_39(){
    cout << "-----ex10.39-----" << endl;
    cout << "list has bidirectional iterator, vector has random-access and bidirectional iterator" << endl;
}

void ex10_40(){
    cout << "-----ex10.40-----" << endl;
    cout << "template <class InputIterator, class OutputIterator> OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result);\n";
    cout << "template <class BidirectionalIterator> void reverse (BidirectionalIterator first, BidirectionalIterator last);\n";
    cout << "template <class ForwardIterator> ForwardIterator unique (ForwardIterator first, ForwardIterator last);" << endl;
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
//    ex10_19(argv[1]);
//    ex10_20(argv[1]);
//   ex10_21();
//    ex10_22(argv[1]);
//    ex10_23();
//    ex10_24();
//    ex10_25(argv[1]);
//    ex10_26();
//    ex10_27();
//    ex10_28();
//    ex10_29(argv[1]);
//    ex10_30();
//    ex10_31();
//    ex10_33(argv[3], argv[4], argv[5]);
//    ex10_34();
//    ex10_35();
//    ex10_36();
//    ex10_37();
//    ex10_38();
//    ex10_39();
    ex10_40();
    return 0;
}
