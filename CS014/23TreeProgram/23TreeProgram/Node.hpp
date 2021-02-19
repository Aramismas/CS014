//
//  Node.hpp
//  23TreeProgram
//
//  Created by Aramis Masarati on 2/23/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Node {

friend class Tree;

private:
  string small;
  string large;

  Node *left;
  Node *middle;
  Node *right;
  Node *parent;

public:
    Node(string data);
    bool isFull();
    bool isLeaf();
  // Add additional functions/variables here. Remember, you may not add any
  // Node * or string variables.
};

#endif /* Node_hpp */
