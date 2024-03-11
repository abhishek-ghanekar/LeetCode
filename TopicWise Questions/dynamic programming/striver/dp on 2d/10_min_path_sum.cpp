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


class Solution {
private:
    bool isRegion(int i,int j,vector<vector<int>> &grid,int threshold) {
        if(abs(grid[i][j] - grid[i][j+1]) > threshold) return false; 
        if(abs(grid[i][j+1] - grid[i][j+2]) > threshold) return false; 
        
        if(abs(grid[i+1][j] - grid[i+1][j+1]) > threshold) return false; 
        if(abs(grid[i+1][j+1] - grid[i+1][j+2]) > threshold) return false; 
        
        if(abs(grid[i+2][j] - grid[i+2][j+1]) > threshold) return false; 
        if(abs(grid[i+2][j+1] - grid[i+2][j+2]) > threshold) return false; 
        
        
        if(abs(grid[i][j] - grid[i+1][j]) > threshold) return false;
        if(abs(grid[i+1][j] - grid[i+2][j]) > threshold) return false;
        
         if(abs(grid[i][j+1] - grid[i+1][j+1]) > threshold) return false;
        if(abs(grid[i+1][j+1] - grid[i+2][j+1]) > threshold) return false;
        
         if(abs(grid[i][j+2] - grid[i+1][j+2]) > threshold) return false;
        if(abs(grid[i+1][j+2] - grid[i+2][j+2]) > threshold) return false;
        
        return true;
        
    }
    void getRegion(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &originalGrid,int threshold,int row,int col,vector<vector<bool>> &vis) {
        if(i + 2 < row && j + 2 < col) {
            // mark it
            // if(i == 1 && j == 0) {
            //     cout << "wow" << endl;
            // }
            if(isRegion(i,j,originalGrid,threshold)) {
                if(i == 1 && j == 0) {
                // cout << "wow" << endl;
            }
                // cout << i << " " << j << endl;
                // then we can continue
                cout << "here" << endl;
                int sum = 0;
                sum += originalGrid[i][j];
                sum += originalGrid[i+1][j];
                sum += originalGrid[i+2][j];
                sum += originalGrid[i][j+1];
                sum += originalGrid[i+1][j+1];
                sum += originalGrid[i+2][j+1];
                sum += originalGrid[i][j+2];
                sum += originalGrid[i+1][j+2];
                sum += originalGrid[i+2][j+2];
                if(i == 1 && j == 0) {
                    cout << "the sum is" << sum << endl;
                }
                // cout << sum << endl;
                int avg = sum/9;
                cout << avg << endl;
                if(vis[i][j]) {
                    int sum = avg + grid[i][j];
                    sum /= 2;
                    grid[i][j] = sum;
                }else {
                    grid[i][j] = avg;
                }
                
                if(vis[i][j+1]) {
                    int sum = avg + grid[i][j+1];
                    sum /= 2;
                    grid[i][j+1] = sum;
                }else {
                    grid[i][j+1] = avg;
                }
                if(vis[i][j+2]) {
                    int sum = avg + grid[i][j+2];
                    sum /= 2;
                    grid[i][j+2] = sum;
                }else {
                    grid[i][j+2] = avg;
                }
                
                if(vis[i+1][j]) {
                    int sum = avg + grid[i+1][j];
                    sum /= 2;
                    grid[i+1][j] = sum;
                }else {
                    grid[i+1][j] = avg;
                }
                if(vis[i+1][j+1]) {
                    int sum = avg + grid[i+1][j+1];
                    sum /= 2;
                    grid[i+1][j+1] = sum;
                }else {
                    grid[i+1][j+1] = avg;
                }
                if(vis[i+1][j+2]) {
                    int sum = avg + grid[i+1][j+2];
                    sum /= 2;
                    grid[i+1][j+2] = sum;
                }else {
                    grid[i+1][j+2] = avg;
                }
                if(vis[i+2][j]) {
                    int sum = avg + grid[i+2][j];
                    sum /= 2;
                    grid[i+2][j] = sum;
                }else {
                    grid[i+2][j] = avg;
                }
                if(vis[i+2][j+1]) {
                    int sum = avg + grid[i+2][j+1];
                    sum /= 2;
                    grid[i+2][j+1] = sum;
                }else {
                    grid[i+2][j+1] = avg;
                }
                if(vis[i+2][j+2]) {
                    int sum = avg + grid[i+2][j+2];
                    sum /= 2;
                    grid[i+2][j+2] = sum;
                }else {
                    grid[i+2][j+2] = avg;
                }
                
                
                vis[i][j] = true;
                vis[i+1][j]= true;
                 vis[i+2][j]= true;
                 vis[i][j+1]= true;
                 vis[i+1][j+1]= true;
                 vis[i+2][j+1]= true;
                 vis[i][j+2]= true;
                 vis[i+1][j+2]= true;
                vis[i+2][j+2]= true;
                // int sum = grid[i][j];
                return ;
            }else {
                return ;
            }
        }else {
            return ;
        }
    }
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int row = image.size();
        vector<vector<int>> ans = image;
        int col = image[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                getRegion(i,j,ans,image,threshold,row,col,vis);
            }
        }
        return ans;
    }
};