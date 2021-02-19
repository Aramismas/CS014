//
//  Vertex.h
//  GraphLab
//
//  Created by Aramis Masarati on 3/7/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

#include <string>
#include <list>
#include <map>
#include <climits>

using namespace std;

class Vertex {
public:
  list<pair<int, int> > neighbors;
  string label;
  int distance;
  string color;
  Vertex* prev;
  
  Vertex():label(""),distance(INT_MAX),color("WHITE"),prev(0){}
  ~Vertex(){}
};

#endif /* Vertex_h */
