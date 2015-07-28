//
//  NotQuery.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__NotQuery__
#define __chapter15__NotQuery__

#include <iostream>
#include <memory>
#include <set>

#include "Query_base.h"
#include "Query.h"
#include "QueryResult.h"

using std::shared_ptr;
using std::cout;
using std::endl;
using std::set;
using std::make_shared;

class NotQuery: public Query_base {
    friend Query operator~(const Query&);
    
    NotQuery (const Query& q): query(q) {
        //cout << "NotQuery::NotQuery(const Query&)" << endl;
    }
    
    QueryResult eval(const TextQuery&) const;
    string rep() const {
        //cout << "NotQuery rep" << endl;
        return "~(" + query.rep() + ")";
    }
    
    Query query;
};

inline Query operator~(const Query &operand) {
    shared_ptr<Query_base> tmp(new NotQuery(operand));
    return tmp;
}

QueryResult NotQuery::eval(const TextQuery& text) const {
    //cout << "NotQuery eval" << endl;
    QueryResult result = query.eval(text);
    shared_ptr<set<line_no>> ret_line = make_shared<set<line_no>>();
    auto beg = result.begin();
    auto end = result.end();
    auto n = result.get_file() -> size();
    for (size_t i = 0; i < n; i++) {
        if (beg == end || *beg != i) {
            ret_line -> insert(i);
        }
        else if (beg != end) {
            beg++;
        }
    }
    return QueryResult(rep(), ret_line, result.get_file());
}

#endif /* defined(__chapter15__NotQuery__) */
