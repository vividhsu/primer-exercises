//
//  Query_base.h
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__Query_base__
#define __chapter15__Query_base__

#include <iostream>
#include <string>

#include "TextQuery.h"

using std::string;
using std::cout;
using std::endl;

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

#endif /* defined(__chapter15__Query_base__) */
