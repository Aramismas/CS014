//
//  IntList.hpp
//  IntList
//
//  Created by Aramis Masarati on 1/16/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef IntList_h
#define IntList_h

#include <stdio.h>
#include <iostream>

struct IntNode {
    int data;
    IntNode* prev;
    IntNode* next;
    IntNode (int data) : data(data), prev(nullptr), next(nullptr) {}
};

class IntList {
    private:
        IntNode* dummyHead;
        IntNode* dummyTail;
    public:
        IntList();
        ~IntList();
        void push_front(int value);
        void pop_front();
        void push_back(int value);
        void pop_back();
        bool empty() const;
        friend std::ostream & operator<<(std::ostream &out, const IntList &rhs);
        void printReverse() const;
};

#endif /* IntList_h */
