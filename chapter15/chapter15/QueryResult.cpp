//
//  QueryResult.cpp
//  chapter15
//
//  Created by vividhsu on 7/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "QueryResult.h"

ostream& print(ostream &os, const QueryResult &qr){
    os << qr.sought << " occurs " << qr.lines -> size() <<" time(s):"<< endl;
    for (auto q: *qr.lines){
        os << "\t(line " << q + 1 << ") " << *(qr.file -> begin() + q) << endl;
    }
    return os;
}
