#include <bits/stdc++.h> 
void dfs(int node,unordered_map<int,list<int>> &adj,stack<int> &s,vector<bool> &visited) {
    visited[node] = true;


    for(auto neighbour:adj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour,adj,s,visited);
        }
    }

    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    //make the adjacency list

    stack<int> s;
    vector<bool> visited(v);
    for(int i=0;i<v;i++) {
        if(!visited[i]) {
            dfs(i,adj,s,visited);
        }
    }

    vector<int> ans;
    while(!s.empty()) {
        int node = s.top();
        s.pop();

        ans.push_back(node);
    }
    return ans;

}