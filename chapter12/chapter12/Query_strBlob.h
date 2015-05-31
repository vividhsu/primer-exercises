
//
//  Query_strBlob.h
//  chapter12
//
//  Created by vividhsu on 5/31/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter12_Query_strBlob_h
#define chapter12_Query_strBlob_h

#include "strBlob.h"

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using std::ostream;
using std::endl;
using std::shared_ptr;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::istringstream;


typedef vector<string>::size_type line_no;

class QueryResult_strBlob{
    friend ostream& print_strBlob(ostream &, QueryResult_strBlob &);
public:
    QueryResult_strBlob(string s, shared_ptr<set<line_no>> p, strBlob f): sought(s), lines(p), file(f) {}
    
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    strBlob file;
};

class TextQuery_strBlob{
public:
    TextQuery_strBlob(ifstream&);
    QueryResult_strBlob query(const string&);
private:
    strBlob file;
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery_strBlob::TextQuery_strBlob(ifstream &infile){
    string text;
    while (getline(infile, text)) {
        file.push_back(text);
        //current line number
        int n = file.size() - 1;
        istringstream line(text);
        string word;
        while (line >> word){
            auto &lines = wm[word];
            if (!lines){
                lines.reset(new set<line_no>);
            }
            lines -> insert(n);
        }
    }
}

QueryResult_strBlob TextQuery_strBlob::query(const string &sought){
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult_strBlob(sought, nodata, file);
    }
    else {
        return QueryResult_strBlob(sought, loc -> second, file);
    }
}

ostream& print_strBlob(ostream &os, QueryResult_strBlob &qr){
    os << qr.sought << " occurs " << qr.lines -> size() << " time(s): " <<  endl;
    for (auto num: *(qr.lines)){
        strBlobPtr sp(qr.file, num);
        os << "\t(line " << num + 1 << ") " << sp.deref() << endl;
    }
    return os;
}

#endif
