
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //make an adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++) {
       int u = g[i].first.first;
       int v = g[i].first.second;
       int w = g[i].second;
       
       adj[u].push_back(make_pair(v,w));
       adj[v].push_back(make_pair(u,w));
    }
    // make the data structures
    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> mst(n+1);
    for(int i=0; i<=n;i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    key[1] = 0;
    parent[1] = -1;
    for(int i=1;i<=n;i++) {
        // process to find the minimum value
        int mini = INT_MAX;
        int u ;
        for(int v=1; v<=n;v++) {
          if (mst[v] == false && key[v] < mini) {
            u = v;
            mini = key[v];
          }
        }
        mst[u] = true;

        //check adjacent nodes
        // update the values if less than previous in the key vectors
        for(auto i:adj[u]) {
            int v = i.first;
            int w = i.second;
            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            } 
        }
    }

    vector<pair<pair<int,int>,int>> result;
    // we run from two as the parent of 1 is -1 , so it will cause an error
    for(int i=2;i<=n;i++) {
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
}
