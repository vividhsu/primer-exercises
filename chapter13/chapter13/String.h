//
//  String.h
//  chapter13
//
//  Created by vividhsu on 6/20/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter13__String__
#define __chapter13__String__



#include <iostream>
#include <utility>
#include <memory>


using std::allocator;
using std::pair;
using std::uninitialized_copy;
using std::cout;
using std::endl;

class String {
public:
    // constructor
    String():beg(nullptr), end(nullptr) {}
    String(const char*);
    // copy constructor
    String(const String&);
    // copy-assignment operator
    String& operator=(const String&);
    //destructor
    ~String();
    
    // member functions
    const char* c_str() const { return beg; };
    size_t size() const { return end - beg; };
    
private:
    // functions for copy control
    pair<char*, char*> alloc_n_copy_s(const char*, const char*);
    void free_s();
    
    // members
    char *beg;
    char *end;
    
    static allocator<char> alloc_s;
};

inline pair<char*, char*> String::alloc_n_copy_s(const char *a, const char *b) {
    char *newData = alloc_s.allocate(b - a);
    return std::make_pair(newData, uninitialized_copy(a, b, newData));
}

inline void String::free_s() {
    for (auto iter = end; iter != beg; ) {
        alloc_s.destroy(--iter);
    }
    alloc_s.deallocate(beg, end - beg);
}

inline String::String(const char* s) {
    char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    auto data = alloc_n_copy_s(s, ++sl);
    beg = data.first;
    end = data.second;
}

inline String::String(const String &rhs) {
    auto data = alloc_n_copy_s(rhs.beg, rhs.end);
    beg = data.first;
    end = data.second;
    cout << "copy constructor for " <<*beg<< endl;
}
 
 
inline String& String::operator=(const String &rhs) {
    auto data = alloc_n_copy_s(rhs.beg, rhs.end);
    free_s();
    beg = data.first;
    end = data.second;
    cout << "copy assignment" << endl;
    return *this;
}
 
 
inline String::~String() {
    free_s();
}




#endif /* defined(__chapter13__String__) */
