//
//  Node.hpp
//  AVLTree
//
//  Created by Aramis Masarati on 2/20/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct Node {
    string data;
    int count;
    Node* left;
    Node* right;
    Node* parent;
    Node(string d);
};


#endif /* Node_hpp */
