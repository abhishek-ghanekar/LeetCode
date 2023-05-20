//  in this question we used bfs to color a graph making sure no two adjacent nodes have the same color


class Solution {
private:
    bool bfs(int node,vector<vector<int>> &graph,vector<int> &color) {
        
        queue<int> q;
        q.push(node);
        color[node] = 0;
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            for(auto edge:graph[frontNode]) {
                if(color[edge] == -1) {
                    if(color[frontNode] == 0) {
                        color[edge] = 1;
                    }else {
                        color[edge] = 0;
                    }
                    q.push(edge);
                }else if(color[edge] == color[frontNode]) {
                 return false;  
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // we are already given an adjacency list
        // we can have a colored map
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                bool ans = bfs(i,graph,color);
                if(!ans) return false;
            }
        }

        return true;
    }
};