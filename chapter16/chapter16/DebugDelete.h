//
//  DebugDelete.h
//  chapter16
//
//  Created by vividhsu on 8/12/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter16__DebugDelete__
#define __chapter16__DebugDelete__

#include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr): os(s) {}
    template <typename T> void operator() (T *p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
    
private:
    std::ostream &os;
};

#endif /* defined(__chapter16__DebugDelete__) */
