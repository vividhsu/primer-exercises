//
//  OrQuery.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__OrQuery__
#define __chapter15__OrQuery__


#include <iostream>
#include <memory>
#include <set>

#include "BinaryQuery.h"
#include "Query.h"
#include "QueryResult.h"

using std::shared_ptr;
using std::cout;
using std::endl;
using std::set;
using std::make_shared;

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    
    OrQuery(const Query& left, const Query& right): BinaryQuery(left, right, "&") {
        //cout << "OrQuery::OrQuery(const Query&, const Query&)" << endl;
    }
    
    QueryResult eval(const TextQuery&) const;
    
};

inline Query operator|(const Query& lhs, const Query& rhs) {
    shared_ptr<Query_base> temp(new OrQuery(lhs, rhs));
    return Query(temp);
}

QueryResult OrQuery::eval(const TextQuery& text) const{
    //cout << "OrQuery eval" << endl;
    QueryResult left = lhs.eval(text);
    QueryResult right = rhs.eval(text);
    shared_ptr<set<line_no>> ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines -> insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

#endif /* defined(__chapter15__OrQuery__) */
