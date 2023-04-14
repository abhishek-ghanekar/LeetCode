#include <bits/stdc++.h>
//function to make adjacent list
//iterate thru the edges vector

void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int, int>> edges) {
    for(int i=0;i<edges.size();i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
} 
void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node) {
    // we need a fifo data structure
  queue<int> q;
  q.push(node);
  visited[node] = true;
  while(!q.empty()) {
      int frontNode = q.front();
      q.pop();
      //push the frontnode in the queue
      ans.push_back(frontNode);
      //process all the neighbours of the frontNode
      for(auto i:adjList[frontNode]) {
        // if node not visited then push into queue
          if(!visited[i]) {
              q.push(i);
              visited[i] = true;
          }
      }

  }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    //adjacent list
    unordered_map<int,set<int>> adjList;
    //unordered map to know if a node is visited
    unordered_map<int,bool> visited(false);
    //ans 
    vector<int> ans;
    //call to make the adjacent list
    prepareAdjList(adjList,edges);

    //lets say if we are given a disconnected graph then we wont be able to process all the vertexs , so for this purpose we call the bfs function on every node if its not visited
    for(int i=0;i<vertex;i++) {
        if(!visited[i]) {
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}