//
//  AdjacencyList.h
//  FinalQuestion1
//
//  Created by Aramis Masarati on 3/17/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef AdjacencyList_hpp
#define AdjacencyList_hpp

#include "Graph.h"

#include <stdio.h>
#include <string>
#include <vector>

struct Node {
    int val;
    std::string color;
    std::vector<int> neighbors;
    std::vector<int> prev;
    Node();
    Node(int v): val(v), color("WHITE") { }
};

class AdjacencyList : public Graph {
    private:
        int numVertex;
        int numEdges;
        std::vector<Node> vertex;
    public:
        AdjacencyList(std::string filename);
        int vertices() const;
        int edges() const;
        int distance(int i) const;
        std::string path(int i) const;
        void bfs(int);
        void dfs(int);
        void recursiveDFS(int);
        void display() const;
};

#endif /* AdjacencyList_h */
