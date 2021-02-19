//
//  Graph.hpp
//  GraphLab
//
//  Created by Aramis Masarati on 3/7/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>

#include "Vertex.h"

using namespace std;

class Graph {
private:
  vector<Vertex> vertices;
public:
  Graph();
  Graph(ifstream&);
  ~Graph();
  void output_graph(const string &);
  void bfs();
  void print();
  int distance(string v);
  Vertex* previous(string v);
};


#endif /* Graph_hpp */
