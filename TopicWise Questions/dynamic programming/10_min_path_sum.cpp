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