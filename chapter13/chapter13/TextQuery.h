//
//  TextQuery.h
//  chapter13
//
//  Created by vividhsu on 6/6/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter13__TextQuery__
#define __chapter13__TextQuery__

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
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    
private:
    shared_ptr<StrVec> file;
    map<string, shared_ptr<set<size_t>>> wm;
};


#endif /* defined(__chapter13__TextQuery__) */
