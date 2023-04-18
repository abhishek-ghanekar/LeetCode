#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // make an adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back( make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    //make a distance array with infinite initially
    vector<int> distance(vertices);
    for(int i=0;i<distance.size();i++) {
        distance[i] = INT_MAX;
    }
    // making the set for the nodes and distance
    // we can also make a priority queue
    set<pair<int,int>> s;
    distance[source] = 0;
    // for entering the values in the set we will use the pair values as distance, node
    s.insert(make_pair(0,source));
    //traverse till set doesnt become empty
    while(!s.empty()) {
        //fetch top node i.e the node with the least distance
        auto top = *(s.begin());
        //auto is used for the computer to automatically understand the data type
        // top is the variable name
        // s.begin() points to the first element as set stores values in a sorted way
        int nodeDistance = top.first;
        int topNode = top.second;

        s.erase(s.begin());
        for(auto neighbour:adj[topNode]) {
            if(nodeDistance + neighbour.second < distance[neighbour.first]) {
                auto record = s.find(make_pair(distance[neighbour.first],neighbour.first));
                //if record found
                if(record != s.end()) {
                  s.erase(record);
                  //s.erase(f) removes the element if found
                }

                distance[neighbour.first] = nodeDistance + neighbour.second;
                // now insert it into set
                s.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }
    }
    return distance;

}
