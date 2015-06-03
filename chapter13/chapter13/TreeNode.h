//
//  TreeNode.h
//  chapter13
//
//  Created by vividhsu on 6/2/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter13_TreeNode_h
#define chapter13_TreeNode_h

#include <iostream>
#include <string>

using std::string;

class TreeNode {
public:
    // constructor
    TreeNode(): count(new int(1)), left(nullptr), right(nullptr) {}
    // copy constructor
    TreeNode(const TreeNode &orig): val(orig.val), count(orig.count), left(orig.left), right(orig.right) { ++*count; }
    //copy-assignment operator
    TreeNode& operator=(const TreeNode&);
    // destructor
    ~TreeNode();
    
private:
    string val;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::~TreeNode(){
    if (--*count == 0){
        delete left;
        delete right;
        delete count;
    }
}

TreeNode& TreeNode::operator=(const TreeNode &rhs){
    ++*rhs.count;
    if (--*count == 0){
        delete left;
        delete right;
        delete count;
    }
    val = rhs.val;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

class BinStrTree {
public:
    // constructor
    BinStrTree(): root(nullptr) {}
    // copy constructor
    BinStrTree(const BinStrTree &orig): root(new TreeNode(*orig.root)) {}
    // copy-assignment operator
    BinStrTree& operator=(const BinStrTree &rhs);
    //destructor
    ~BinStrTree() {delete root; }
private:
    TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree &rhs){
    TreeNode *temp = new TreeNode(*rhs.root);
    delete root;
    root = temp;
    return *this;
}

#endif
