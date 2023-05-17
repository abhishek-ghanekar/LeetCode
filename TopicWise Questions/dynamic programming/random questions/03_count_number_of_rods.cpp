// using memoization 
int f(int n,int x,int y,int z,vector<int> &memo) {
	if(n == 0) return 0;
    if(n < 0) return -1e9;
	if(memo[n] != -1) return memo[n];
	int cutIntoX = 1 + f(n-x,x,y,z,memo);
	int cutIntoY = 1 + f(n-y,x,y,z,memo);
	int cutIntoZ = 1 + f(n-z,x,y,z,memo);

	return memo[n] = max(cutIntoX,max(cutIntoY,cutIntoZ));

}
int cutSegments(int n, int x, int y, int z) {
	vector<int> memo(n+1,-1);
	if(f(n,x,y,z,memo) < 0) {
		return 0;
	}else {
		return f(n,x,y,z,memo);
	}
	// return f(n,x,y,z);
}

// using tabulation

int cutSegments(int n, int x, int y, int z) {

	vector<int> dp(n+1,0);
	dp[0] = 0;
	for(int i=1;i<=n;i++) {
		int a = -1e9;
		int b = -1e9;
		int c = -1e9;
		if(i-x >= 0) a = 1 + dp[i-x];
		if(i-y >= 0) b = 1 + dp[i-y];
		if(i-z >= 0) c = 1 + dp[i-z];
	
                  
                dp[i] = max(a,max(b,c));
	}
	if(dp[n] < 0) return 0;
	return dp[n];
}