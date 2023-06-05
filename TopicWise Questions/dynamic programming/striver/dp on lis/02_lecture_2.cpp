#include <vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    //we calculate the lis for all the values that ends with i
    int maxi = 1;
    for(int i=0;i<n;i++){
       for(int j=0;j<=i;j++) {
           if(arr[j] < arr[i]) {
               // usko daal sakte hain in lis
               dp[i] = max(dp[i],1 + dp[j]);
           }
       }
       maxi = max(maxi,dp[i]);
    }
    return maxi;
}

