//
//  AdjacencyMatrix.cpp
//  FinalQuestion2
//
//  Created by Aramis Masarati on 3/18/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include "AdjacencyMatrix.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(string filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Input file not found." << endl;
        exit(1);
    }
    int v, first, second;
    fin >> v;
    numVertex = 0;
    numVertex = v;
    numEdges = 0;
    matrix = vector<vector<bool> >(numVertex, vector<bool>(numVertex, false));
    _previous = vector<int>(numVertex, -1);
    int i = 0;
    while (i < numVertex) {
        fin >> first >> second;
        Node v(first);
        matrix.at(first).at(second) = true;
        vertex.push_back(v);
        _distances.push_back(0);
        numEdges++;
        i++;
    }
    while (fin >> first) {
        fin >> second;
        matrix.at(first).at(second) = true;
        numEdges++;
    }
    fin.close();
}

int AdjacencyMatrix::vertices() const {
    return numVertex;
}

int AdjacencyMatrix::edges() const {
    return numEdges;
}

int AdjacencyMatrix::distance(int i) const {
    return _distances.at(i);
}

string AdjacencyMatrix::path(int i) const {
    if (i == 0) {
        return "{0}";
    }
    vector<int> p;
    string paths = "{0->";
    int temp = i;
    while (temp != 0) {
        p.push_back(temp);
        temp = _previous.at(temp);
    }
    int size = p.size();
    for (int j = size; j - 1 >= 0; j--) {
        paths += to_string(p.at(j - 1));
        if (j-1 != 0) {
            paths += "->";
        }
    }
    paths += "}";
    return paths;
}

// Overall runtime complexity: O(n^2) where n is the number of vertices
// Overall space complexity: O(n) where n is the number of vertices
void AdjacencyMatrix::bfs(int i) {
    queue<Node> q; // O(1)
    Node temp(i); // O(1)
    q.push(temp); // O(1)
    temp.col = "GRAY"; // O(1)
    while (!q.empty()) { // O(n) where n is the number of vertices
        Node n = q.front(); // O(1)
        q.pop(); // O(1)
        for (unsigned i = 0; i < matrix.at(n.val).size(); i++) { // O(n) where n is the number of vertices
            if ((vertex.at(i).col == "WHITE") && (matrix.at(n.val).at(i) == true)) { // O(1)
                _distances.at(i) = _distances.at(n.val) + 1; // O(1)
                _previous.at(i) = n.val; // O(1)
                vertex.at(i).col = "GRAY"; // O(1)
                Node v(i); // O(1)
                v.col = vertex.at(i).col; // O(1)
                q.push(v); // O(1)
            }
        }
       vertex.at(n.val).col = "BLACK"; // O(1)
    }
}

// Overall runtime complexity: O(n^2) where n is the number of vertices
// Overall space complexity: O(n) where n is the number of vertices
void AdjacencyMatrix::dfs(int i) {
    recursiveDFS(i); // O(n^2) where n is the number of vertices
}

void AdjacencyMatrix::recursiveDFS(int v) {
    vertex.at(v).col = "GRAY"; // O(1)
    for (unsigned i = 0; i < matrix.at(v).size(); i++) { // O(n) where n is the number of vertices
            if ((vertex.at(i).col == "WHITE") && (matrix.at(v).at(i) == true)) { // O(1)
                _distances.at(i) = _distances.at(v) + 1; // O(1)
                _previous.at(i) = v; // O(1)
                vertex.at(i).col = "GRAY"; // O(1)
                recursiveDFS(i); // O(n) where n is the number of vertices
            }
     }
     vertex.at(v).col = "BLACK"; // O(1)
}


void AdjacencyMatrix::display() const {
    cout << "{ ";
    for (int i = 0; i < numVertex; i++) {
        cout << vertex.at(i).val << " ";
        cout << endl;
    }
    for (int i = 0; i < numVertex; i++) {
        for (unsigned j = 0; j < numVertex; j++) {
            if (matrix.at(i).at(j) == true) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "}" << endl;
}

