//
//  Sales_data.h
//  chapter10
//
//  Created by vividhsu on 5/15/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter10_Sales_data_h
#define chapter10_Sales_data_h

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
inline bool compareIsbn(const Sales_data&, const Sales_data&);

#endif
