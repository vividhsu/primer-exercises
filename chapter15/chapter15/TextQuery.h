//
//  TextQuery.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__TextQuery__
#define __chapter15__TextQuery__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <sstream>

#include "QueryResult.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::map;
using std::set;
using std::ifstream;
using std::istringstream;

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


#endif /* defined(__chapter15__TextQuery__) */
