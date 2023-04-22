// to find the minimum distance from source to destination
#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<m;j++) {
           int u = edges[j][0];
           int v = edges[j][1];
           int wt = edges[j][2];

           if(dist[u] != 1e9 && (dist[u] + wt) < dist[v]) {
            dist[v] = dist[u] + wt;
        }
        } 
    }
    return dist[dest];
}
// to find if a negative cycle exists
#include <bits/stdc++.h> 
bool detectNegativeCycle(int n, int m, vector<vector<int>> &edges)
{
	 vector<int> dist(n+1, 0);
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != INT_MAX && (long long)dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        if(dist[u] != INT_MAX && (long long)dist[u] + wt < dist[v]) {
            return true;
        }
    }

    return false;
}