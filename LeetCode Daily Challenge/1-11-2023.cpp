//find the minimum time taken to collect all the apples

class Solution {
private:
    int dfs(int node,int parent,vector<vector<int>> &adj,vector<bool> &hasApple) {
        int totaltime = 0;
        int childtime = 0;
        for(auto child:adj[node]) {
            if(child == parent) continue;
            childtime = dfs(child,node,adj,hasApple);
            if(childtime || hasApple[child]) totaltime += childtime +2;
        }
        return totaltime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //creating an adjacency list
        vector<vector<int>> adj(n);
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        //return the answer
        return dfs(0,-1,adj,hasApple);
    }
};