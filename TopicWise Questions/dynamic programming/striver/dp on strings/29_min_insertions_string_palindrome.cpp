#include <bits/stdc++.h> 
int minInsertion(string &s)
{
    // we need to make the string a palindrome
    // that requires us to find the length of longest palindrome subsequence
    string t = s;
    reverse(s.begin(),s.end());
    int m = s.length();
    int n = t.length();
    vector<int> prev(n+1,0);
    vector<int> curr(n+1,0);
    // for(int i=0;i<=m;i++) memo[i][0] = 0;
    // for(int i=0;i<=n;i++) memo[0][i] = 0;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(s[i-1] == t[j-1]) {
                curr[j] = 1 + prev[j-1];
            }else {
                curr[j] = max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }
    // prev[n] is the longest common subsequenc
    return m - prev[n];
}