#include <bits/stdc++.h> 
bool compare(string curr,string prev) {
    // we need to check if after adding a single element to j we can get i
    if(prev.size() >= curr.size()) return false;
    if(curr.size() - prev.size() > 1) return false;
    // now we have made sure the length of prev is curr - 1
    int i = 0;
    int j = 0;
    while(i < curr.size()) {
        if(curr[i] == prev[j]) {
            i++;
            j++;
        }else {
            i++;
        }
    }
    return i == curr.size() && j == prev.size();
}
bool cmp(string &s1,string &s2 ) {
   return s1.size() < s2.size();
}
int longestStrChain(vector<string> &arr)
{
    // we need to use the lis method
    // x xx y xyx
    int n = arr.size();
    sort(arr.begin(),arr.end(),cmp);
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            // we compare the i and j if j forms a feasible subseqeunce then we add it
            if(compare(arr[i],arr[j]) && 1 + dp[j] > dp[i]) {
                // we found a good value
                dp[i] = 1 + dp[j];
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
        }
    }
    return maxi;
}