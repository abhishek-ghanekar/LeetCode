#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<int> indegree(v);
    for(auto i:adj) {
        for(auto j:i.second) {
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto neighbour:adj[frontNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return ans;
}