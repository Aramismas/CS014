//
//  main.cpp
//  FinalQuestion1
//
//  Created by Aramis Masarati on 3/16/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include "AdjacencyList.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    AdjacencyList al("input.txt");
    
    al.display();
    
    /*
    cout << "Performing BFS..." << endl;
    al.bfs(0);
    for (unsigned i = 0;i < al.vertices();++i) {
        cout << "Path: " << al.path(i) << " at a distance of " << al.distance(i) << endl;
    }
    cout << endl;
     */
    
    cout << "Performing DFS..." << endl;
    al.dfs(0);
    /*
    for (unsigned i = 0; i < al.vertices(); i++) {
        cout << al.distance(i) << endl;
    }
     */
    for (unsigned i = 0;i < al.vertices();++i) {
        cout << "Path: " << al.path(i) << " at a distance of " << al.distance(i) << endl;
    }
    cout << endl;
    
    return 0;
}
