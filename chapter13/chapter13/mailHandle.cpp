//
//  mailHandle.cpp
//  chapter13
//
//  Created by vividhsu on 6/3/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "mailHandle.h"


void Message::add_to_Folders(const Message &m) {
    for (auto f: m.folders) {
        f -> addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for (auto f: folders) {
        f -> remMsg(this);
    }
    folders.clear();
}

void Message::move_Folders(Message *m) {
    folders = std::move(m -> folders);
    for (auto f: folders) {
        f -> remMsg(m);
        f -> addMsg(this);
    }
    m -> folders.clear();
}

Message::Message(const Message &m): content(m.content), folders(m.folders) {
    add_to_Folders(m);
}


Message& Message::operator=(const Message &m) {
    remove_from_Folders();
    content = m.content;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Message::Message(Message &&m): content(std::move(m.content)) {
    move_Folders(&m);
}

Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_Folders();
        content = std::move(rhs.content);
        move_Folders(&rhs);
    }
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Folder::add_to_Messages(const Folder &f) {
    for (auto m: f.messages) {
        m -> addFdr(this);
    }
}

void Folder::remove_from_Messages() {
    for (auto m: messages) {
        m -> remFdr(this);
    }
    messages.clear();
}

Folder::Folder(const Folder &f): messages(f.messages) {
    add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &f) {
    remove_from_Messages();
    messages = f.messages;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder() {
    remove_from_Messages();
}

void Folder::save(Message &m) {
    messages.insert(&m);
    m.addFdr(this);
}

void Folder::remove(Message &m) {
    messages.erase(&m);
    m.remFdr(this);
}





