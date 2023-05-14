//memoization solution
#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &memo) {
    if(i == 0 && j == 0) return grid[i][j];
    if(i < 0 || j < 0) return 1e9 ;
    if(memo[i][j] != -1) return memo[i][j];
    int up = grid[i][j] + f(i-1,j,grid,memo);
    int left = grid[i][j] + f(i,j-1,grid,memo);

    return memo[i][j] = min(left,up);
}
int minSumPath(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> memo(row,vector<int>(col,-1));
    return f(row-1,col-1,grid,memo);
}

//tabulation solution
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    // dp[0][0] = grid[0][0];
    for(int i= 0;i<m;i++) {
        for(int j= 0 ; j<n; j++) {
            if(i == 0 && j == 0){
               dp[i][j] = grid[i][j] ;
               
            }else {
                int left = 1e9;
                int top = 1e9;
                if(i > 0) top = grid[i][j] + dp[i-1][j];
                if(j > 0) left = grid[i][j] + dp[i][j-1];
        
                dp[i][j] = min(left,top);
            } 
            
        }
    }
    return dp[m-1][n-1];
}

// Space optimization solution


#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n,0);
    for(int i=0;i<m;i++) {
        vector<int> curr(n,0);
        for(int j=0;j<n;j++) {
           if(i == 0 && j == 0) {
                curr[j] = grid[i][j];
            }else {
                int top = 1e9;
                int left = 1e9;
                if(i > 0) top = grid[i][j] + prev[j];
                if(j > 0) left = grid[i][j] + curr[j-1];
                curr[j] = min(top,left);
            }
        }
        prev = curr;
    }
    return prev[n-1];
}