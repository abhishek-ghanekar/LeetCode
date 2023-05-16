
// using recursion

#include <bits/stdc++.h>
bool f(int index, int target,vector<int> arr) {
  if (target == 0)
    return true;
  if (index == 0)
    return arr[index] == target;

  bool notPick = f(index - 1, target,arr);
  bool pick = false;
  if (target >= arr[index])
    pick = f(index-1,target-arr[index],arr);
  return notPick || pick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    return f(n-1,k,arr);
}

// using memoization
#include <bits/stdc++.h>
bool f(int index, int target,vector<int> arr,vector<vector<int>> &memo) {
  if (target == 0)
    return true;
  if (index == 0)
    return arr[index] == target;
  if(memo[index][target] != -1) return memo[index][target];
  bool notPick = f(index - 1, target,arr,memo);
  bool pick = false;
  if (target >= arr[index])
    pick = f(index-1,target-arr[index],arr,memo);
  return  memo[index][target] = notPick || pick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> memo(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,memo);
}

//using tabulation
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
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
    return dp[n-1][k];
}
