//
//  main.cpp
//  chapter11
//
//  Created by vividhsu on 5/24/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <list>
#include <utility>

#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::set;
using std::string;
using std::ifstream;
using std::remove_if;
using std::vector;
using std::istringstream;
using std::list;
using std::multiset;
using std::pair;


void ex11_1(){
    cout << "-----ex11.1-----" << endl;
    cout << "map is an associative container which stores and achieve elements by keys;\n";
    cout << "vector is a swquential container which stores and access elements by positions." << endl;
}

void ex11_2(){
    cout << "-----ex11.2-----" << endl;
    cout << "list: non-contiguous memory, no pre-allocate memory, not support random-access, easily insertion and erasure, also combine list by splice. \n";
    cout << "vector: contiguous memory, pre-allocate memory, random access, easily insert and remove at the end. \n";
    cout << "deque: non-contiguous memory, random access, easily insert and remove at the beginning and end.\n";
    cout << "map: stores key and value, access the value by key.\n";
    cout << "set: only stores key which is unique." << endl;
}

void ex11_3(const char *title){
    cout << "-----ex11.3-----" << endl;
    map<string, size_t> counter;
    ifstream input(title);
    string word;
    while (input >> word){
        ++counter[word];
    }
    for (auto &c: counter){
        cout << c.first << " occurs " << c.second << ((c.second > 1) ? " times" : " time") <<endl;
    }
    input.close();
}

void ex11_4(const char *title){
    //refer to https://github.com/Mooophy/Cpp-Primer/blob/master/ch11/ex11_3_4.cpp
    cout << "-----ex11.4-----" << endl;
    map<string, size_t> counter;
    ifstream input(title);
    string word;
    while (input >> word){
        for (auto &c: word)
            c = tolower(c);
        word.erase(remove_if(word.begin(), word.end(), ispunct),word.end());
        ++counter[word];
    }
    for (auto &c: counter){
        cout << c.first << " occurs " << c.second << ((c.second > 1) ? " times" : " time") <<endl;
    }
    input.close();
}

void ex11_5(){
    cout << "-----ex10.5-----" << endl;
    cout << "map contains key and value, set only contains key. \n";
    cout << "if we need both key and value, choose map, otherwise, choose set" << endl;
}

void ex11_6(){
    cout << "-----ex10.6-----" << endl;
    cout << "set has unique key. list may have duplicate values." << endl;
}

void ex11_7(const char* title){
    cout << "-----ex10.7-----" << endl;
    map<string, vector<string>> names;
    ifstream input(title);
    string line;
    while (getline(input, line)){
        istringstream words(line);
        string lastName;
        words >> lastName;
        vector<string> firstName;
        string name;
        while(words >> name){
            firstName.push_back(name);
        }
        if (names.find(lastName) == names.end()){
            names.insert({lastName, firstName});
        }
    }
    for (auto &l: names) {
        cout << l.first << ": ";
        for(auto &c: l.second){
            cout << c << " ";
        }
        cout <<"\n";
    }
    cout << endl;
    input.close();
}

void ex11_8(){
    cout << "-----ex10.8-----" << endl;
    cout << "set is unique and ordered." << endl;
}

void ex11_9(){
    cout << "-----ex10.9-----" << endl;
    map<string, list<string::size_type>> smap;
}

void ex11_10(){
    //ref to https://github.com/Mooophy/Cpp-Primer/blob/master/ch11/ex11_9_10.cpp
    cout << "-----ex10.10-----" << endl;
    map<vector<int>::iterator, int> vmap;
    map<list<int>::iterator, int> lmap;
    cout << "vector iterator is random-access iterator, has < operation; \n";
    cout << "list iterator is bidirectional iterator, no < operation" << endl;
}

void ex11_11(){
    cout << "-----ex10.11-----" << endl;
    multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
    cout << "multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);" <<endl;
}

void ex11_12_13(){
    cout << "-----ex10.12 and ex10.13----" << endl;
    vector<pair<string, int>> pv;
    string s;
    int i;
    while (cin >> s >> i){
//        pv.push_back({s, i});
//        pv.push_back(make_pair(s, i));
        pv.push_back(pair<string, int>(s, i));
    }
    for (auto &v: pv){
        cout << v.first << " " << v.second << "\n";
    }
    cout << endl;
    
}

void ex11_14(const char* title){
    cout << "-----ex10.14-----" << endl;
    map<string, vector<pair<string, string>>> families;
    ifstream input(title);
    string line;
    while (getline(input, line)){
        istringstream words(line);
        string lastName;
        words >> lastName;
        string firstName, birth;
        vector<pair<string, string>> children;
        while(words >> firstName >> birth){
            children.push_back({firstName, birth});
        }
        if (families.find(lastName) == families.end()){
            families.insert({lastName, children});
        }
    }
    for (auto &f: families) {
        cout << f.first << ": ";
        for(auto &p: f.second){
            cout << p.first << " " << p.second << ", ";
        }
        cout <<"\n";
    }
    cout << endl;
    input.close();
}

void ex11_15(){
    cout << "-----ex11.15-----" << endl;
    cout << "a map from int to vector<int>: ";
    cout << "map<int, vector<int>> imap;\n";
    cout << "mapped type is vector<int>\n";
    cout << "key type is int\n";
    cout << "value_type is pair<int, vector<int>>" << endl;
}

void ex11_16(){
    cout << "-----ex11.16-----" << endl;
    map<string, std::size_t> word_cout{{"word", 4}};
    auto map_it = word_cout.begin();
    map_it -> second = 5;
    cout << map_it -> first << " " << map_it -> second << endl;
}

void ex11_17(){
    cout << "-----ex11.17-----" << endl;
    multiset<string> c1, c2, c3={"a", "an", "the"}, c4={"a", "an", "the"};
    vector<string> v1={"a", "an", "the"}, v2={"a", "an", "the"}, v3, v4;
    //legal
    copy(v1.begin(), v1.end(), inserter(c1, c1.end()));
    //illegal, mutliset doesn't have push_back
//    copy(v2.begin(), v2.end(), back_inserter(c2));
    //legal
    copy(c3.begin(), c3.end(), inserter(v3, v3.end()));
    //legal
    copy(c4.begin(), c4.end(), back_inserter(v4));
    for (auto &i: c1){
        cout << i << " ";
    }
    cout << endl;
    for (auto &i: c2){
        cout << i << " ";
    }
    cout << endl;
    for (auto &i: v3){
        cout << i << " ";
    }
    cout << endl;
    for (auto &i: v4){
        cout << i << " ";
    }
    cout << endl;
}

void ex11_18(){
    cout << "-----ex11.18-----" << endl;
    map<string, std::size_t> word_cout;
    map<string, std::size_t>::iterator map_it = word_cout.begin();
    
    cout << "map<string, size_t> word_cout;\n";
    cout << "map<string, std::size_t>::iterator map_it = word_cout.begin();" << endl;
}

void ex11_19(){
    cout << "-----ex11.19-----" << endl;
    multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
    multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)>::iterator set_it = bookstore.begin();
    cout << "multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);\n";
    cout << "multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)>::iterator set_it = bookstore.begin();" <<endl;
}

int main(int argc, const char * argv[]) {
//    ex11_1();
//    ex11_2();
//    ex11_3(argv[1]);
//    ex11_4(argv[1]);
//    ex11_5();
//    ex11_6();
//    ex11_7(argv[2]);
//    ex11_8();
//    ex11_9();
//    ex11_10();
//    ex11_11();
//    ex11_12_13();
//    ex11_14(argv[3]);
//    ex11_15();
//    ex11_16();
//    ex11_17();
//    ex11_18();
    ex11_19();
    return 0;
}
