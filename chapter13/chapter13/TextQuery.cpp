//
//  TextQuery.cpp
//  chapter13
//
//  Created by vividhsu on 6/6/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "TextQuery.h"

#include <sstream>

using std::istringstream;

TextQuery::TextQuery(ifstream &is):file(new StrVec()){
    string text;
    while (getline(is, text)) {
        file -> push_back(text);
        int n = file -> size() - 1;  //current line number
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines){
                lines.reset(new set<size_t>);
            }
            lines -> insert(n);
        }
        
    }
}

QueryResult TextQuery::query(const string &sought) const{
    static shared_ptr<set<size_t>> nodata(new set<size_t>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    }
    else {
        return QueryResult(sought, loc -> second, file);
    }
}

ostream& print(ostream &os, const QueryResult &qr){
    os << qr.sought << " occurs " << qr.lines -> size() <<" time(s):"<< std::endl;
    for (auto q: *qr.lines){
        os << "\t(line " << q + 1 << ") " << *(qr.file -> begin() + q) << std::endl;
    }
    return os;
}
