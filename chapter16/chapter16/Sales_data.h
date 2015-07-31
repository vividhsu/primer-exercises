//
//  Sales_data.h
//  chapter16
//
//  Created by vividhsu on 7/30/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter16__Sales_data__
#define __chapter16__Sales_data__

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Sales_data{
public:
    friend void ex10_12(const char*);
    friend ostream& print(ostream &, const Sales_data&);
    // constructors
    Sales_data () = default;
    Sales_data (string& s): bookNo(s) {}
    
    // member functions
    string isbn() const {return bookNo;}
private:
    //
    string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

ostream& print(ostream&, const Sales_data &);
inline bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs){
    return lhs.isbn() < rhs.isbn();
}


#endif /* defined(__chapter16__Sales_data__) */
