//
//  TextQuery.cpp
//  chapter12
//
//  Created by vividhsu on 5/31/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "TextQuery.h"
#include "QueryResult.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using std::ostream;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::istringstream;

TextQuery::TextQuery(ifstream &is):file(new vector<string>){
    string text;
    while (getline(is, text)) {
        file -> push_back(text);
        int n = file -> size() - 1;  //current line number
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines){
                lines.reset(new set<line_no>);
            }
            lines -> insert(n);
        }
        
    }
}

QueryResult TextQuery::query(const string &sought) const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    }
    else {
        return QueryResult(sought, loc -> second, file);
    }
}

ostream& print(ostream &os, const QueryResult &qr){
    os << qr.sought << " occurs " << qr.lines -> size() <<" time(s):"<< endl;
    for (auto q: *qr.lines){
        os << "\t(line " << q + 1 << ") " << *(qr.file -> begin() + q) << endl;
    }
    return os;
}
