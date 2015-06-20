
//
//  QueryResult.h
//  chapter13
//
//  Created by vividhsu on 6/6/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter13_QueryResult_h
#define chapter13_QueryResult_h


#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>

#include "StrVec.h"

using std::ostream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::set;

class QueryResult{
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<size_t>> p, shared_ptr<StrVec> f): sought(s), lines(p), file(f) {}
    set<size_t>::const_iterator begin() const {return lines -> cbegin(); }
    set<size_t>::const_iterator end() const { return lines -> cend(); }
    shared_ptr<StrVec> get_file() { return file; }
private:
    string sought;
    shared_ptr<set<size_t>> lines;
    shared_ptr<StrVec> file;
};

ostream& print(ostream&, const QueryResult&);

#endif
