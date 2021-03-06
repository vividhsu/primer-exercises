
//
//  QueryResult.h
//  chapter12
//
//  Created by vividhsu on 5/30/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter12_QueryResult_h
#define chapter12_QueryResult_h

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>

using std::ostream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::set;

class QueryResult{
    friend ostream& print(ostream&, const QueryResult&);
public:
    typedef vector<string>::size_type line_no;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f): sought(s), lines(p), file(f) {}
    set<line_no>::const_iterator begin() const {return lines -> cbegin(); }
    set<line_no>::const_iterator end() const { return lines -> cend(); }
    shared_ptr<vector<string>> get_file() { return file; }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream& print(ostream&, const QueryResult&);

#endif
