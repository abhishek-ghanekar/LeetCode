// tabulation approach

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int mini = 1e9;
	int sum = 0;
	for(auto i:arr) sum += i;
	int k = sum;
	vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    //base case when the target is zero
    for(int i=0;i<n;i++) dp[i][0] = true;
	
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
      for (int target = 1; target <= k; target++) {
        bool notPick = dp[i-1][target];
        bool pick = false;
        if(target >= arr[i]) pick = dp[i-1][target-arr[i]];
        dp[i][target] = pick || notPick;
      }
    }
	// we need to find subsets from 0 to s2
	for(int i=0;i<=sum/2;i++) {
		//if the target is possible
		if(dp[n-1][i]) {
			int s1 = i;
			int s2 = sum - i;
			int value = abs(s2-s1);
			mini = min(value,mini);
		}
	}
	return mini;
}

// space optimization solution
#include <bits/stdc++.h> 

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int mini = 1e9;
	int sum = 0;
	for(auto i:arr) sum += i;
	int k = sum;
	// vector<vector<bool>> dp(n,vector<bool>(k+1,false));
	vector<bool> prev(k+1,false);
	vector<bool> curr(k+1,false);
	prev[0] = true;
	curr[0] = true;
    //base case when the target is zero
    // for(int i=0;i<n;i++) dp[i][0] = true;
	
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
      for (int target = 1; target <= k; target++) {
        bool notPick = prev[target];
        bool pick = false;
        if(target >= arr[i]) pick = prev[target-arr[i]];
        curr[target] = pick || notPick;
      }
	  prev = curr;
    }
	// we need to find subsets from 0 to s2
	for(int i=0;i<=sum/2;i++) {
		//if the target is possible
		if(prev[i]) {
			int s1 = i;
			int s2 = sum - i;
			int value = abs(s2-s1);
			mini = min(value,mini);
		}
	}
	return mini;
}
