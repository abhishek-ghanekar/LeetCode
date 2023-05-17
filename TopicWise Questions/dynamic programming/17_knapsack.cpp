// using memoization
#include <bits/stdc++.h> 
int f(int index,vector<int> &value,vector<int> &weight,int maxWeight,vector<vector<int>> &memo) {

	if(maxWeight == 0) return 0;
	if(index == 0) {
		// if we reach the 0th index
		if(maxWeight == 0 || weight[index] > maxWeight) return 0;
		return value[index];
	} 
	if(memo[index][maxWeight] != -1) return memo[index][maxWeight];
	int steal = -1e9;
	if(weight[index] <= maxWeight) {
		 steal = value[index] + f(index-1,value,weight,maxWeight-weight[index],memo);
	}
	int notSteal = f(index-1,value,weight,maxWeight,memo);
	return memo[index][maxWeight] = max(steal,notSteal);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> memo(n,vector<int>(maxWeight+1,-1));
	return f(n-1,value,weight,maxWeight,memo);
}

// using tabulation
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	vector<vector<int>> memo(n,vector<int>(maxWeight+1,0));

	for(int i=weight[0];i<=maxWeight;i++) memo[0][i] = value[0];
 
	for(int i=1; i<n ;i++) {
		for(int j=1;j<=maxWeight;j++) {
		    int notSteal = memo[i-1][j];
			int steal = -1e9;
			if(weight[i] <= j) {
				steal = value[i] + memo[i-1][j-weight[i]];
			}
			memo[i][j] = max(steal,notSteal);
		}
	}
	return memo[n-1][maxWeight];
}

//space optimization
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);
	vector<int> curr(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++) prev[i] = value[0];
	for(int i=1; i<n ;i++) {
		for(int j=1;j<=maxWeight;j++) {
		    int notSteal = prev[j];
			int steal = -1e9;
			if(weight[i] <= j) {
				steal = value[i] + prev[j-weight[i]];
			}
			curr[j] = max(steal,notSteal);
		}
		prev = curr;
	}
	return prev[maxWeight];
}