//
//  Graph.cpp
//  GraphLab
//
//  Created by Aramis Masarati on 3/7/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include "Graph.h"

Graph::Graph() {
    
}

Graph::Graph(ifstream& fin) {
    map<string, int> vertexEdge;
    int vertexs;
    int edges;
    int cost;
    string vertexLabel;
    fin >> vertexs >> edges;
    for (int i = 0; i < vertexs; i++) {
        Vertex v;
        fin >> vertexLabel;
        v.label = vertexLabel;
        vertices.push_back(v);
        vertexEdge[vertexLabel] = i;
    }
    string v1;
    string v2;
    for (int i = 0; i < edges; i++) {
        fin >> v1 >> v2 >> cost;
        int index = vertexEdge[v1];
        pair<int, int> p(vertexEdge[v2], cost);
        vertices.at(index).neighbors.push_back(p);
    }
}

/*
void Graph::print() {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices.at(i).label << "[label = \"" << vertices.at(i).label << ", " << vertices.at(i).distance << "\"]" << endl;
        if (!vertices.at(i).neighbors.empty()) {
            list<pair<int, int> > ::iterator it = vertices.at(i).neighbors.begin();
            while (it != vertices.at(i).neighbors.end()) {
                   cout << vertices.at(i).label << " -> " << vertices.at(it->first).label << endl;
               it++;
            }
        }
        cout << endl;
    }
}
*/

Graph::~Graph() {
    while (vertices.size() != 0) {
        vertices.pop_back();
    }
}

void Graph::output_graph(const string & fileName) {
    ofstream outFS(fileName.c_str());
     if (!outFS.is_open()){
         cout<<"Error"<<endl;
         return;
     }
     outFS<<"digraph G {"<<endl;
     for (unsigned i = 0; i < vertices.size(); i++) {
         if (vertices.at(i).distance != INT_MAX) {
         outFS << vertices.at(i).label << "[label = \"" << vertices.at(i).label << ", " << vertices.at(i).distance << "\"]" << endl;
             if (!vertices.at(i).neighbors.empty()) {
                 list<pair<int, int> > ::iterator it = vertices.at(i).neighbors.begin();
                 while (it != vertices.at(i).neighbors.end()) {
                        outFS << vertices.at(i).label << " -> " << vertices.at(it->first).label << endl;
                    it++;
                 }
             }
         }
     }
     outFS<<"}";
     outFS.close();
     string jpgFilename = fileName.substr(0,fileName.size()-4)+".jpg";
     string command = "dot -Tpng " + fileName + " -o " + jpgFilename;
     system(command.c_str());
     return;
}

void Graph::bfs() {
    map <string, unsigned> cloud;
    for (unsigned i = 0; i < vertices.size(); i++) {
        vertices.at(i).color = "WHITE";
        vertices.at(i).distance = INT_MAX;
        vertices.at(i).prev = nullptr;
        cloud[vertices.at(i).label] = i;
    }
    vertices.at(0).color = "GRAY";
    vertices.at(0).distance = 0;
    queue<Vertex> q;
    q.push(vertices.at(0));
    while (!q.empty()) {
        Vertex v = q.front();
        q.pop();
        list<pair<int, int> >::iterator it = v.neighbors.begin();
        while (it != v.neighbors.end()) {
            if (vertices.at(it->first).color == "WHITE") {
                vertices.at(it->first).color = "GRAY";
                vertices.at(it->first).distance = v.distance + it->second;
                vertices.at(it->first).prev = &vertices.at(cloud[v.label]);
                q.push(vertices.at(it->first));
            }
            ++it;
        }
    }
}

int Graph::distance(const string & v) const {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).label == v) {
            return vertices.at(i).distance;
        }
    }
    return -1;
}

string Graph::previous(const string & v) const {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).label == v) {
            if (vertices.at(i).prev != nullptr) {
                return vertices.at(i).prev->label;
            }
        }
    }
    return "";
}
