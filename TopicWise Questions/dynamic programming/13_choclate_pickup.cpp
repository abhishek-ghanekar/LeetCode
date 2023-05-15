// memoization solution
#include <bits/stdc++.h> 
int f(int i,int j1,int j2,vector<vector<int>> &grid,int r,int c,vector<vector<vector<int>>> &memo) {
    //base case 
    //always write the out of bound base case first
    if(j1 < 0 || j2 <0 || j1 >= c|| j2 >= c) return -1e9;
    //destination base case
    if(memo[i][j1][j2] != -1) return memo[i][j1][j2];
    if(i == r-1) {
        if(j1 == j2){
          return grid[i][j1];
        }else {
            return grid[i][j1] + grid[i][j2];
        }
    }

    // now we do the recursion calls
    int maxi = -1e8;
    for(int dj1=-1; dj1<= +1 ; dj1++) {
        for(int dj2=-1;dj2 <= +1; dj2++) {
            int value = 0;
            if(j1 == j2) {
                value = grid[i][j1];
            }else {
                value = grid[i][j1] + grid[i][j2];
            }
            value += f(i+1,j1+dj1,j2+dj2,grid,r,c,memo);
            maxi = max(maxi,value);
        }
    }
    return memo[i][j1][j2] = maxi;

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> memo(r,vector<vector<int>>(c,vector<int>(c,-1)));
    // matrix is R x c
    // that means there are r columns
    // that means there are c columns
    return f(0,0,c-1,grid,r,c,memo);
}