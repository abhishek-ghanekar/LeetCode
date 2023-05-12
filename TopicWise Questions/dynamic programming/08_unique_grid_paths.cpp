

#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>> &memo) {
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	if(memo[i][j] != -1) return memo[i][j];
	int left = f(i,j-1,memo);
	int top = f(i-1,j,memo);
	return memo[i][j] = left+top;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	// apply memoization
	vector<vector<int>> memo(m,vector<int>(n,-1));
	return f(m-1,n-1,memo);
}

//tabulation solution

#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
	int dp[m][n];
    for(int i = 0; i < m ;i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0 ){
                 dp[i][j] = 1;
			}else {
               int up = 0;
			   int left = 0;
				if(i > 0) up = dp[i-1][j];
				if(j > 0) left = dp[i][j-1];

               dp[i][j] = up+left;
			}       
        }
    }
	return dp[m-1][n-1];
}

// space optimization solution
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<int> prev(n,0);
    for(int i=0;i<m;i++) {
		vector<int> curr(n,0);
		for(int j=0; j < n ; j++) {
			if(i == 0 && j == 0) curr[j] = 1;
			else {
			   int up = 0;
			   int left = 0;
			   if(i > 0) up = prev[j];
			   if(j > 0) left = curr[j-1];
			   curr[j] = up + left;
			}
		}
		prev = curr;
	}
	return prev[n-1];
}