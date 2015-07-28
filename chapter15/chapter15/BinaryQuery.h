//
//  BinaryQuery.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__BinaryQuery__
#define __chapter15__BinaryQuery__

#include <iostream>
#include <string>

#include "Query_base.h"
#include "Query.h"

using std::string;
using std::cout;
using std::endl;

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query& l, const Query& r, string s): lhs(l), rhs(r), opSym(s) {
        //cout << "BinaryQuery::BinaryQuery(const Query&, const Query&, string)" << endl;
    }
    
    string rep() const {
        //cout << "BinaryQuery rep" << endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    
    Query lhs, rhs;
    string opSym;
};

#endif /* defined(__chapter15__BinaryQuery__) */
