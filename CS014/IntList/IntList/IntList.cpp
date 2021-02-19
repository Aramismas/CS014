//
//  IntList.cpp
//  IntList
//
//  Created by Aramis Masarati on 1/16/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include "IntList.h"
#include <iostream>
using namespace std;
// default constructor for the IntList
IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}
// destructor for the IntList class, removes every node
IntList::~IntList() {
    IntNode* temp = dummyHead;
       while (temp != nullptr) {
           delete temp;
           temp = temp->next;
       }
}
// inserts a new node of data in front of the list
void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);
    temp->next = dummyHead->next;
    temp->prev = dummyHead;
    dummyHead->next->prev = temp;
    dummyHead->next = temp;
}
// removes a node of data in front of the list
void IntList::pop_front() {
    if (empty()) {
        return;
    }
    IntNode* temp = dummyHead->next;
    dummyHead->next = dummyHead->next->next;
    dummyHead->next->prev = dummyHead;
    delete temp;
}
// inserts a new node of data in the back of the list
void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    temp->next = dummyTail;
    temp->prev = dummyTail->prev;
    dummyTail->prev->next = temp;
    dummyTail->prev = temp;
}
// removes a node of data in the back of the list
void IntList::pop_back() {
    if (empty()) {
        return;
    }
    IntNode* temp = dummyTail->prev;
    dummyTail->prev = dummyTail->prev->prev;
    dummyTail->prev->next = dummyTail;
    delete temp;
}
// checks to see whether the list is empty and returns true if it is
bool IntList::empty() const {
    return (dummyHead->next == dummyTail);
}
// outputs the entire contents within the list when using cout
ostream & operator<<(ostream & out, const IntList & rhs) {
    if (rhs.empty()) {
        return out;
    }
    IntNode* temp = rhs.dummyHead->next;
    while (temp->next != rhs.dummyTail) {
        out << temp->data << " ";
        temp = temp->next;
    }
    out << temp->data;
    return out;
}
// outputs the entire contents within the list in reverse
void IntList::printReverse() const {
    if (empty()) {
        return;
    }
    IntNode* temp = dummyTail->prev;
    while (temp->prev != dummyHead) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << temp->data;
}

