#include <vector>
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    //we calculate the lis for all the values that ends with i
    // to trace the lis we will store the parent index of all elements
    vector<int> parent(n);
    int lastIndex = 0;
    int maxi = 1;
    for(int i=0;i<n;i++){
       parent[i] = i;
       for(int j=0;j<=i;j++) {
           if(arr[j] < arr[i] && 1 + dp[j] > dp[i]) {
               // usko daal sakte hain in lis
               dp[i] = 1 + dp[j];
               parent[i] = j;
           }
       }
       if(dp[i] > maxi) {
           maxi = dp[i];
           lastIndex = i;
       }
    }

    vector<int> lis(maxi);
    int index = 1;
    lis[0]  = arr[lastIndex];
    while(parent[lastIndex] != lastIndex) {
         lastIndex = parent[lastIndex];
         lis[index++] = arr[lastIndex];
    }
    reverse(lis.begin(),lis.end());
    for(auto it:lis) cout << it << " ";
    cout << endl;
    return maxi;
}
