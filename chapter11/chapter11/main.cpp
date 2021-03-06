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
#include <exception>

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
using std::multimap;


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

void ex11_20(const char* title){
    cout << "-----ex11.20-----" << endl;
    ifstream input(title);
    map<string, size_t> word_count;
    string word;
    while (input >> word){
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {
            ++ret.first -> second;
        }
    }
    for (auto &c: word_count){
        cout << c.first << " occurs " << c.second << ((c.second > 1) ? " times" : " time") <<endl;
    }
    input.close();
}

void ex11_21(){
    cout << "-----ex11.21-----" << endl;
/**   
    map<string, size_t> word_count;
    string word;
    while (cin >> word){
        ++word_count.insert({word,0}).first->second;
    }
*/
    cout << "insert {word, 0} to the map, if map already has word, increase the count" << endl;
}

void ex11_22(){
    cout << "-----ex11.22-----" << endl;
    map<string, vector<int>> smap;
    pair<map<string, vector<int>>::iterator, bool> ret = smap.insert({"abc", {1,2,3}});
    cout << ret.second << endl;
}

void ex11_23(const char* title){
    cout << "-----ex11.23-----" << endl;
    multimap<string, string> families;
    ifstream input(title);
    string line;
    while (getline(input, line)){
        istringstream words(line);
        string lastName;
        words >> lastName;
        string firstName;
        while(words >> firstName){
            families.insert({lastName, firstName});
        }
    }
    for (auto &f: families) {
        cout << f.first << " " << f.second << "\n";
    }
    cout << endl;
    input.close();
}

void ex11_24(){
    cout << "-----ex11.24-----" << endl;
    map<int, int> m;
    m[0] = 1;
    cout << "search if m contains key 0, because m is empty, insert {0,0} to m, assign value 1 to key 0." <<endl;
}

void ex11_25(){
    cout << "-----ex11.25-----" << endl;
    cout << "Unlike map, if vector is empty, we can't subscript it." << endl;
}

void ex11_26(){
    cout << "-----ex11.26-----" << endl;
    cout << "key_type can be used to subscript a map;\n";
    cout << "mapped_type is the map return type." << endl;
}

void ex11_27(){
    cout << "-----ex11.27-----" << endl;
    cout << "if I only need to find out whether the key is present, I can use count;\n";
    cout << "if I need to know the position of the key, I can use find" << endl;
}

void ex11_28(){
    cout << "-----ex11.28-----" << endl;
    map<string, vector<int>> m{{"aaa", {1,2,3}}, {"bb", {4,5}}};
    map<string, vector<int>>::iterator iter = m.find("bb");
    cout << iter -> first <<": ";
    for (auto &i: iter -> second){
        cout << i << " ";
    }
    cout << endl;
}

void ex11_29(){
    cout << "-----ex11.29-----" << endl;
    cout << "if a key k is not in the container:\n";
    cout << "lower_bound returns the iterator which the key is greater than k.\n";
    cout << "upper_bound returns the iterator which the key is greater than k.\n";
    cout << "equal_range returns a pair of <iterator, iterator>, both iterator points to the key greater than k.\n";
    cout << "lower_bound and upper_bound point to the same key." << endl;
}

void ex11_30(){
    cout << "-----ex11.30-----" << endl;
    multimap<string, string> authors;
    string search_item;
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
        cout << pos.first -> second << endl;
    cout << "pos.first -> second means the lower_bound item's value" << endl;
}

void ex11_31(){
    cout << "-----ex11.31-----" << endl;
    multimap<string, string> authors{{"AA", "aaaa"},{"CC", "cccc"},{"AA", "bbb"},{"DD", "eee"},{"CC", "vvv"}};
    for (auto &author: authors) {
        cout << author.first << ": " << author.second << "\n";
    }
    string search_item = "AA";
    auto iter = authors.find(search_item);
    auto cnt = authors.count(search_item);
    while (cnt){
        auto iter1 = iter;
        iter1++;
        authors.erase(iter);
        --cnt;
        iter = iter1;
    }
    cout << "after erase:\n";
    for (auto &author: authors) {
        cout << author.first << ": " << author.second << "\n";
    }
    cout << endl;
}

void ex11_32(){
    // refer to https://github.com/Mooophy/Cpp-Primer/blob/master/ch11/ex11_32.cpp
    cout << "-----ex11.32-----" << endl;
    multimap<string, string> authors{{"AA", "b"},{"CC", "xxx"},{"AA", "a"},{"DD", "eee"},{"CC", "vvv"}};
    for (auto &author: authors) {
        cout << author.first << ": " << author.second << "\n";
    }
    map<string, multiset<string>> order_authors;
    for (auto &author: authors){
        //order_authors[author.first] is the mapped type of order_authors, which is multiset<string>
        //.insert(author.second) insert the value type of multiset<string>, which is string
        order_authors[author.first].insert(author.second);
    }

    cout << "after reorganize:\n";
    for (auto &author: order_authors) {
        cout << author.first << ": ";
        for (auto &c: author.second){
            cout << c << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

map<string, string> buildMap(ifstream &map_file){
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);
        }
        else
            throw std::runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string& transform(const string &word, map<string, string> &trans_map){
    auto iter = trans_map.find(word);
    if (iter != trans_map.end()) {
        return iter -> second;
    }
    else{
        return word;
    }
}

void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool isFirst = true;
        while (stream >> word) {
            if(isFirst){
                isFirst = false;
            }
            else{
                cout << " ";
            }
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

void ex11_33(const char* title1, const char* title2){
    cout << "-----ex11.33-----" << endl;
    ifstream map_file(title1);
    ifstream input(title2);
    word_transform(map_file, input);
    map_file.close();
    input.close();
}

void ex11_34(){
    cout << "-----ex11.34-----" << endl;
    cout << "if key is not in the map, subscript will adds the key to the map." << endl;
}

void ex11_35(){
    cout << "-----ex11.35-----" << endl;
    cout << "if the key is already there, it won't overwrite the value." << endl;
}

map<string, string> buildMap1(ifstream &map_file){
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
        value = value.substr(1);
        if (value.size() > 1) {
            trans_map[key] = value;
        }
        else
            throw std::runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string& transform1(const string &word, map<string, string> &trans_map){
    auto iter = trans_map.find(word);
    if (iter != trans_map.end()) {
        return iter -> second;
    }
    else{
        return word;
    }
}

void word_transform1(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap1(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool isFirst = true;
        while (stream >> word) {
            if(isFirst){
                isFirst = false;
            }
            else{
                cout << " ";
            }
            cout << transform1(word, trans_map);
        }
        cout << endl;
    }
}

void ex11_36(const char* title1, const char* title2){
    cout << "-----ex11.36-----" << endl;
    ifstream map_file(title1);
    ifstream input(title2);
    word_transform1(map_file, input);
    map_file.close();
    input.close();
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
//    ex11_19();
//    ex11_20(argv[1]);
//    ex11_21();
//    ex11_22();
//    ex11_23(argv[2]);
//    ex11_24();
//    ex11_25();
//    ex11_26();
//    ex11_27();
//    ex11_28();
//    ex11_29();
//    ex11_30();
//    ex11_31();
//    ex11_32();
//    ex11_33(argv[4], argv[5]);
//    ex11_34();
//    ex11_35();
//    ex11_36(argv[6], argv[5]);
    return 0;
}
