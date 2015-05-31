//
//  TextQuery.h
//  chapter12
//
//  Created by vividhsu on 5/30/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter12_TextQuery_h
#define chapter12_TextQuery_h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

#include "QueryResult.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::map;
using std::set;
using std::ifstream;

class QueryResult;

class TextQuery{
public:
    typedef vector<string>::size_type line_no;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

#endif
