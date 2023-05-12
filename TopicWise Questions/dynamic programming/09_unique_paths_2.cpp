//using memoization 
int mod = (int)(1e9+7);
int f(int i,int j,vector<vector<int>> &memo,vector<vector<int>> &mat) {
    
    if(i >=0 && j>= 0 && mat[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    
    if(memo[i][j] != -1) return memo[i][j];

    int top = f(i-1,j,memo,mat);
    int left = f(i,j-1,memo,mat);
    
    return memo[i][j] = (left+top) % mod;   
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> memo(n,vector<int>(m,-1));
    return f(n-1,m-1,memo,mat);
}

//using tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    // vector<vector<int>> memo(n,vector<int>(m,-1));
    // return f(n-1,m-1,memo,mat);
    //tabulation approach
    int dp[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else {
                int top = 0;
                int left = 0;
                if(i > 0) top = dp[i - 1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = (top + left) % mod;
            } 
        }
    }
    return dp[n-1][m-1] ;
}

// using space optimization solution