//using recursion 
#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>> &matrix) {
    if(j < 0 || j >= matrix[0].size()) return -1e9;
    if(i == 0) return matrix[0][j];
    
    
    int goUp = matrix[i][j] + f(i-1,j,matrix);
    int goDiagonalLeft = matrix[i][j] + f(i-1,j-1,matrix);
    int goDiagonalRight = matrix[i][j] + f(i-1,j+1,matrix);

    return max(goUp,max(goDiagonalLeft,goDiagonalRight));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{

    int m = matrix[0].size();
    int maxi = -1e9;
    for(int j=0;j<m;j++) {
        maxi = max(maxi,f(n-1,j,matrix));
    }
    return maxi;
}
//using memoization
#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &memo) {
    if(j < 0 || j >= matrix[0].size()) return -1e9;
    if(i == 0) return matrix[0][j];
    if(memo[i][j] != -1)return memo[i][j];
    
    int goUp = matrix[i][j] + f(i-1,j,matrix,memo);
    int goDiagonalLeft = matrix[i][j] + f(i-1,j-1,matrix,memo);
    int goDiagonalRight = matrix[i][j] + f(i-1,j+1,matrix,memo);

    return memo[i][j] = max(goUp,max(goDiagonalLeft,goDiagonalRight));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();
    vector<vector<int>> memo(n,vector<int>(m,-1));
    int maxi = -1e9;
    for(int j=0;j<m;j++) {
        maxi = max(maxi,f(n-1,j,matrix,memo));
    }
    return maxi;
}
//using tabulation
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int maxi = -1e9;
    // make the inital answers as 0
    for(int i=0;i<m;i++) dp[0][i] = matrix[0][i];


    //perform tabulation
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
          int goUp = matrix[i][j] + dp[i-1][j];
          int goDiagonalLeft = matrix[i][j];
          if(j - 1 >= 0) {
              goDiagonalLeft += dp[i-1][j-1];
          }else {
              goDiagonalLeft += -1e9;
          }
          int goDiagonalRight = matrix[i][j];
          if(j+1 < m) {
              goDiagonalRight += dp[i-1][j+1];
          }else {
              goDiagonalRight += -1e9;
          }
          dp[i][j] = max(goUp,max(goDiagonalLeft,goDiagonalRight));
        }
    }


    // int maxi = -1e9;
    for(int j=0;j<m;j++) {
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}

//space optimization solution
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    //using space optimization
    vector<int> prev(m,0);
    vector<int> curr(m,0);
    // vector<vector<int>> dp(n,vector<int>(m,0));
    int maxi = -1e9;
    // make the inital answers as 0
    for(int i=0;i<m;i++) prev[i] = matrix[0][i];


    //perform tabulation
    for(int i=1;i<n;i++) {
        
        for(int j=0;j<m;j++) {
          int goUp = matrix[i][j] + prev[j];
          int goDiagonalLeft = matrix[i][j];
          if(j - 1 >= 0) {
              goDiagonalLeft += prev[j-1];
          }else {
              goDiagonalLeft += -1e9;
          }
          int goDiagonalRight = matrix[i][j];
          if(j+1 < m) {
              goDiagonalRight += prev[j+1];
          }else {
              goDiagonalRight += -1e9;
          }
          curr[j] = max(goUp,max(goDiagonalLeft,goDiagonalRight));
        }
        prev = curr;
    }


    // int maxi = -1e9;
    for(int j=0;j<m;j++) {
        maxi = max(maxi,prev[j]);
    }
    return maxi;
}