//
//  mailHandle.h
//  chapter13
//
//  Created by vividhsu on 6/3/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter13__mailHandle__
#define __chapter13__mailHandle__

#include <iostream>
#include <string> 
#include <set>

using std::string;
using std::set;

class Folder;

class Message {
    friend class Folder;
public:
    // constructor
    Message(const string &str = ""): content(str) {}
    // copy-constructor
    Message(const Message&);
    // copy-assignment operator
    Message& operator=(const Message&);
    //move constructor
    Message(Message&&);
    // move assignment operator
    Message& operator=(Message&&);
    //destructor
    ~Message();
    
    // member functions
    void save(Folder&);
    void remove(Folder&);
    
private:
    // member
    string content;
    set<Folder*> folders;
    
    // private auxiliary functions
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message *m);
    
    void addFdr(Folder *f) { folders.insert(f); }
    void remFdr(Folder *f) { folders.erase(f); }
};

class Folder {
    friend class Message;
public:
    //constructor
    Folder() = default;
    // copy-constructor
    Folder(const Folder&);
    // copy-assignment operator
    Folder& operator=(const Folder&);
    //destructor
    ~Folder();
    
    // member functions
    void save(Message&);
    void remove(Message&);
private:
    //member
    set<Message*> messages;
    
    void add_to_Messages(const Folder&);
    void remove_from_Messages();
    
    void addMsg(Message *m) { messages.insert(m); }
    void remMsg(Message *m) { messages.erase(m); }
};

#endif /* defined(__chapter13__mailHandle__) */
