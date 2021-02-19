//
//  Node.cpp
//  23TreeProgram
//
//  Created by Aramis Masarati on 2/23/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include "Node.hpp"

Node::Node(string data) {
    small = data;
    large = " ";
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}

bool Node::isFull() {
    if ((small != " ") && (large != " ")) {
        return true;
    }
    return false;
}

bool Node::isLeaf() {
    if ((left == nullptr) && (middle == nullptr) && (right == nullptr)) {
        return true;
    }
    return false;
}
