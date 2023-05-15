// memoization solution
#include <bits/stdc++.h> 
int f(int i,int j, vector<vector<int>> &triangle,int n,vector<vector<int>> &memo) {

	if(i == n-1) return triangle[i][j];
    if(memo[i][j] != -1) return memo[i][j];
    int goDown = triangle[i][j] + f(i+1,j,triangle,n,memo);
	int goDiagonal = triangle[i][j] + f(i+1,j+1,triangle,n,memo);

	return memo[i][j] = min(goDown,goDiagonal);

}
int minimumPathSum(vector<vector<int>>& triangle, int n){

	vector<vector<int>> memo(n,vector<int>(n,-1));
	return f(0,0,triangle,n,memo);
}

//tabulation solution
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> memo(n,vector<int>(n,0));
	// turning this into tabulation
	// first we need to fill all the bottom rows of the triangle
    for(int i=0;i<n;i++) memo[n-1][i] = triangle[n-1][i];

	// now we need to go from back to top
	for(int i = n-2; i >=0 ;i--) {
		for(int j=i;j>=0;j--) {
			int d = triangle[i][j] + memo[i+1][j];
			int dg = triangle[i][j] + memo[i+1][j+1];
			memo[i][j] = min(d,dg);
		}
	}
	
	return memo[0][0];
}
//space optimization solution
int minimumPathSum(vector<vector<int>> &triangle,int n ) {
	vector<int> prev(n,0);
	//filling the last row first
	for(int i=0;i<n;i++) prev[i] = triangle[n-1][i];

	//now we start from bottom to up
	for(int i = n-2; i>=0 ; i--) {
		vector<int> curr(n,0);
		for(int j=i;j>=0;j--) {
			int down = triangle[i][j] + prev[j];
			int diagonal = triangle[i][j] + prev[j+1];
			curr[j] = min(down,diagonal);
		}
		prev = curr;
	}
    return prev[0];
}