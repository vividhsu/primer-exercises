//
//  Foo.h
//  chapter13
//
//  Created by vividhsu on 6/20/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter13_Foo_h
#define chapter13_Foo_h
#include <iostream>
#include <vector>

using std::vector;


class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    std::cout << "call rvalue" << std::endl;
    return *this;
}

Foo Foo::sorted() const & {
    /** normal
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
    */
    
    /** ex13.56
    Foo ret(*this);
    std::cout << "call lvalue" << std::endl;
    return ret.sorted();
    */
    
    std::cout << "call lvalue" << std::endl;
    return Foo(*this).sorted();
}

#endif
