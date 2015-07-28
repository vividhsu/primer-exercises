//
//  Query.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__Query__
#define __chapter15__Query__

#include <iostream>
#include <memory>
#include <string>

#include "Query_base.h"
#include "WordQuery.h"

using std::shared_ptr;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Query {
    
public:
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
    
    Query(const string& s): q(new WordQuery(s)) {
        // cout << "Query::Query(const string&)" << endl;
    }
    
    
    QueryResult eval(const TextQuery &t) const {
        //cout << "Query eval" << endl;
        return q -> eval(t);
    }
    string rep() const {
        //cout << "Query rep" << endl;
        return q -> rep();
    }
    
private:
    Query(shared_ptr<Query_base> query): q(query) {
        //cout << "Query::Query(shared_ptr<Query_base>)" << endl;
    }
    shared_ptr<Query_base> q;
};

ostream& operator<<(ostream& os, const Query query) {
    return os << query.rep();
}

#endif /* defined(__chapter15__Query__) */
