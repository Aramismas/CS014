//
//  main.cpp
//  IntList
//
//  Created by Aramis Masarati on 1/16/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include <iostream>
#include "IntList.h"

using namespace std;
// checks to make sure the IntList class works properly
int main() {
    cout << "List 1" << endl;
    IntList list;
    list.printReverse();
    if (list.empty()) {
        cout << "The list is empty" << endl;
    }
    list.push_back(2);
    list.push_front(1);
    list.push_back(3);
    list.push_back(4);
    list.pop_back();
    list.pop_front();
    cout << list << "hi" << endl;
    list.push_back(5);
    list.push_back(6);
    list.printReverse();
    cout << endl;
    {
        cout << "List 2" << endl;
        IntList list2;
        cout << list2;
        list2.push_front(2);
        list2.push_front(1);
        list2.push_back(3);
        cout << list2 << endl;
        
    }
    cout << "Called list2 destructor" << endl;
    return 0;
}
