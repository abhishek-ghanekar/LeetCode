#include <unordered_map>
#include <queue>
#include <list>
bool isCyclic(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj) {
    queue<int> q;
    unordered_map<int,int> parent;
    q.push(node);
    visited[node] = true; 
    parent[node] = -1;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto neighbour:adj[frontNode]) {
            if(visited[neighbour] == true && neighbour != parent[frontNode]) {
                return true;
            }else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
        
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++) {
      int u = edges[i][0];
      int v = edges[i][1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    

    // to handle all components
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++) {
       if(!visited[i]) {
           bool ans = isCyclic(i,visited,adj);
           if(ans == 1) {
               return  "Yes";
           }
       }
    }
    
    return "No";
           

}
