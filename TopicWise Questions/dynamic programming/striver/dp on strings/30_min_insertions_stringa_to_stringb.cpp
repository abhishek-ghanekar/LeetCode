#include <bits/stdc++.h> 
int canYouMake(string &s, string &t)
{
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
    int deleteOperations = m - prev[n];
    int addOperations = n - prev[n];
    return deleteOperations + addOperations;
}