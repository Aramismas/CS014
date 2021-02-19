//
//  AdjacencyMatrix.h
//  FinalQuestion2
//
//  Created by Aramis Masarati on 3/18/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef AdjacencyMatrix_hpp
#define AdjacencyMatrix_hpp

#include "Graph.h"
#include <stdio.h>
#include <string>
#include <vector>

struct Node {
    int val;
    std::string col;
    Node(int v): val(v), col("WHITE") {}
};

class AdjacencyMatrix : public Graph {
    private:
        int numVertex;
        int numEdges;
        std::vector<Node> vertex;
        std::vector<std::vector<bool> > matrix;
    public:
        AdjacencyMatrix(std::string filename);
        int vertices() const;
        int edges() const;
        int distance(int i) const;
        std::string path(int i) const;
        void bfs(int);
        void dfs(int);
        void recursiveDFS(int);
        void display() const;

};


#endif /* AdjacencyMatrix_h */
