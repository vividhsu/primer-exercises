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

int main(int argc, const char * argv[]) {
//    ex11_1();
//    ex11_2();
//    ex11_3(argv[1]);
//    ex11_4(argv[1]);
//    ex11_5();
//    ex11_6();
//    ex11_7(argv[2]);
    ex11_8();
    return 0;
}