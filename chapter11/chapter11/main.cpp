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


using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::set;
using std::string;
using std::ifstream;
using std::remove_if;

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



int main(int argc, const char * argv[]) {
//    ex11_1();
//    ex11_2();
//    ex11_3(argv[1]);
    ex11_4(argv[1]);
    return 0;
}
