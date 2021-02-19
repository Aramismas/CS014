//
//  Graph.h
//  FinalQuestion1
//
//  Created by Aramis Masarati on 3/17/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <vector>

class Graph {
    protected:
        std::vector<int> _distances;
        std::vector<int> _previous;
    public:
        Graph() { }
        virtual int vertices() const = 0;
        virtual int edges() const = 0;
        virtual int distance(int) const = 0;
        virtual void bfs(int) = 0;
        virtual void dfs(int) = 0;
        virtual void display() const = 0;
};

#endif /* Graph_h */
