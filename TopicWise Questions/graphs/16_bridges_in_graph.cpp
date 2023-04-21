#include <bits/stdc++.h>
void dfs(int node,int parent,int timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &result,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited )  {
   visited[node] = true;  
   disc[node] = low[node] = timer;
   timer++;
   for(auto neighbour:adj[node]) {
       if(neighbour == parent) {
          continue;
       }
       if(!visited[neighbour]) {

         dfs(neighbour,node,timer,disc,low,result,adj,visited);

         low[node] = min(low[node],low[neighbour]);
        //  check if edge is bridge
        if(low[neighbour] > disc[node]) {
            vector<int> ans;
            ans.push_back(node);
            ans.push_back(neighbour);
            result.push_back(ans);
        }
       }else {
           // this means its a back edge
           low[node] = min(low[node],disc[neighbour]);
       }
   }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++) {
        int v = edges[i][0];
        int u = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    vector<vector<int>> result;
    //now do dfs
    for(int i=0;i<v;i++) {
        if(!visited[i]) {
            dfs(i,parent,timer,disc,low,result,adj,visited);
        }
    }
    return result;
}
