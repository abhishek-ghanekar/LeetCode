#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &arr){
    // we need to print the maximum list
    // 1 3 5 7 11
    int n = arr.size(); 
    vector<int> dp(n,1);
    vector<int> parent(n);
    int lastIndex = 0;
    int maxi = 1;
    
    sort(arr.begin(),arr.end());
    for(int curr=0;curr<n;curr++) {
        parent[curr] = curr;
       for(int prev=0;prev<curr;prev++) {
           if(arr[curr]%arr[prev] == 0 && 1 + dp[prev] > dp[curr]) {
               dp[curr] = 1 + dp[prev];
               parent[curr] = prev; 
           }
       }
       if(dp[curr] > maxi) {
           maxi = dp[curr];
           lastIndex = curr;
       }
    }
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    // int index = 1;
    while(parent[lastIndex] != lastIndex) {
        lastIndex = parent[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    

}