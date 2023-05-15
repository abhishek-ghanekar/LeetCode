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