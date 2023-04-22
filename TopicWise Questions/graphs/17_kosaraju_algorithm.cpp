#include <bits/stdc++.h>
void dfs(int node,stack<int> &s,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj) {
	visited[node] = true;

	for(auto neighbour:adj[node]) {
		if(!visited[neighbour]) {
			dfs(neighbour,s,visited,adj);
		}
	}
	s.push(node);
}
void revDfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &trans) {
   visited[node] = true;
   for(auto neighbour:trans[node]) {
		if(!visited[neighbour]) {
			revDfs(neighbour,visited,trans);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//first make an adjacent list
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}

	//find the topological sort
	stack<int> s;
	unordered_map<int,bool> visited;
	for(int i=0;i<v;i++) {
		if(!visited[i]){
			dfs(i,s,visited,adj);
		}
	}
	// transpose the graph
	//new graph
	unordered_map<int,list<int>> trans;
	for(int i=0;i<v;i++) {
		visited[i] = false;
		for(auto j:adj[i]) {
			trans[j].push_back(i);
		}
	}
	//dfs call for the transpose
	int count = 0;
	while(!s.empty()) {
		int top = s.top();
		s.pop();
		if(!visited[top]) {
			count++;
			revDfs(top,visited,trans);
		}
	}
	return count;
}