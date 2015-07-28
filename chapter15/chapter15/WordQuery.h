//
//  WordQuery.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__WordQuery__
#define __chapter15__WordQuery__

#include <iostream>
#include <string>

#include "Query_base.h"

using std::string;
using std::cout;
using std::endl;

class WordQuery: public Query_base {
    friend class Query;
    
    WordQuery(const string &s): query_word(s) {
        // cout << "WordQuery::WordQuery(const string&): " + s << endl;
    }
    
    QueryResult eval(const TextQuery& t) const {
        //cout << "WordQuery eval" << endl;
        return t.query(query_word);
    }
    string rep() const {
        //cout << "WordQuery rep" << endl;
        return query_word;
    }
    
    string query_word;
};

#endif /* defined(__chapter15__WordQuery__) */
