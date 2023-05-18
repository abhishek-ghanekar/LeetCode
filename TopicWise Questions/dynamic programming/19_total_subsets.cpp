//using memoization
#include <bits/stdc++.h> 
int f(int index,int target,vector<int> &arr,vector<vector<int>> &memo) {
  if(target == 0) return 1;
  if(index == 0){
         return arr[0] == target;
   }
  if(memo[index][target] != -1) return memo[index][target];
  int notPick = f(index - 1, target,arr,memo);
  int pick = 0;
  if (target >= arr[index]) {
       pick = f(index-1,target-arr[index],arr,memo);
  }
  return memo[index][target] = pick + notPick;
    
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    sort(num.begin(), num.end(), greater<int>());
    vector<vector<int>> memo(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,memo);
}