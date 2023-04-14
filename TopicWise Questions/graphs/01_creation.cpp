#include<iostream>
using namespace std;
#include <unordered_map>
#include <list>
class graph {
  public:
   unordered_map<int,list<int >> adj;
   void addEdge(int u,int v,bool direction) {
    if(direction == 0) {
        //undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
   }
   void print() {
    for(auto i : adj) {
        cout << i.first << "->";
        for(auto j : i.second) {
            cout << j << ",";
        }
        cout << endl;

    }
   }
};
int main()
{
    int n;
    cout << "enter number of nodes" << endl;
    cin >> n;

    int m;
    cout << "enter number of edges" << endl;
    cin >> m;
    graph g;
    for(int i =0; i<m;i++) {
        int u,v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v,0);

    }
    g.print();
    return 0;
}





// #include <bits/stdc++.h> 
// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     // Write your code here.
//     vector<int> ans(n);
//     //for every node we insert its connected nodes
//     // in this all nodes are represented by the index
//     //for example a[0] contains all the values connected to the node 0
//     // this is one way of representing graphs i guess
//     for(int i=0;i<m;i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }
//     //after this we would have a vector which for the index number node has the neighbouring nodes
//     //answer format is vector<vector<int>>
//     vector<vector<int>> adj(n);
//     for(int i=0;i<n;i++) {
//         adj[i].push_back(i);
//         for(int j=0;j<ans[i].size();j++) {
//             adj[i].push_back(ans[i][j]);
//         }
//     }
//     return adj;
// }