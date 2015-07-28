//
//  AndQuery.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__AndQuery__
#define __chapter15__AndQuery__

#include <iostream>
#include <memory>
#include <algorithm>
#include <set>
#include <iterator>

#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"


using std::shared_ptr;
using std::cout;
using std::endl;
using std::set_intersection;
using std::set;
using std::make_shared;
using std::inserter;

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    
    AndQuery(const Query& left, const Query& right): BinaryQuery(left, right, "&") {
        // cout << "AndQuery::AndQuery(const Query&, const Query&)" << endl;
    }
    
    QueryResult eval(const TextQuery&) const;
    
};

inline Query operator&(const Query& lhs, const Query& rhs) {
    shared_ptr<Query_base> temp(new AndQuery(lhs, rhs));
    return Query(temp);
}

QueryResult AndQuery::eval(const TextQuery &text) const {
    //cout << "AndQuery eval" << endl;
    QueryResult left = lhs.eval(text);
    QueryResult right = rhs.eval(text);
    shared_ptr<set<line_no>> ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines -> begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

#endif /* defined(__chapter15__AndQuery__) */
