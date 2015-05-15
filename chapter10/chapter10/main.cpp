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

using std::count;
using std::accumulate;
using std::equal;
using std::vector;
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

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

int main(int argc, const char * argv[]) {
//    ex10_1();
//    ex10_2();
//    ex10_3();
//    ex10_4();
    ex10_5();
    return 0;
}
