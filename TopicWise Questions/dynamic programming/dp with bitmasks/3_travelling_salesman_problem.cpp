#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getMinCost(int i,int mask,vector<vector<int>> dist,int n) {
    // if we reach back to city i and all cities are visited
    if(mask == 0) {
        return dist[i][0];
    }
    int minCost = INT_MAX;
    for(int j=0;j<n;j++) {
        if(mask & (1<<j)) {
            minCost = min(minCost,dist[i][j] + getMinCost(j,(mask^(1<<j)),dist,n));
        }
    }
    return minCost;

    
}
int main()
{
    
    vector<vector<int>> dist = {{12, 30, 33, 10, 45},
{56, 22, 9, 15, 18},
{29, 13, 8, 5, 12},
{33, 28, 16, 10, 3},
{1, 4, 30, 24, 20}
};

    // we got the distance vector
    cout << getMinCost(0,(1<<(5-2)),dist,5);
    return 0;
}