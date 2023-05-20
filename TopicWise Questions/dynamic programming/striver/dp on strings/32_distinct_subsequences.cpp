// using memoization
#include <bits/stdc++.h>
// int mod = 1e9 + 7; 
int f(int i,int j,string &t,string &s,vector<vector<int>> &memo) {
    // theres two index for string1 and string2
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(t[i] == s[j]) {
        return f(i-1,j,t,s,memo) + f(i-1,j-1,t,s,memo);
    }
        return f(i-1,j,t,s,memo);
    
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> memo(lt,vector<int>(ls,-1));
    return f(lt-1,ls-1,t,s,memo);
} 

//using tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i =0 ; i<m+1;i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1] == t[j-1]) {
                  dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else {
                  dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[m][n];
    }
};

//using space optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        // vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        vector<double> prev(n+1,0);
        prev[0] = 1;
        vector<double> curr(n+1,0);
        curr[0] = 1;
        // for(int i =0 ; i<m+1;i++) {
        //     dp[i][0] = 1;
        // }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1] == t[j-1]) {
                  curr[j] = prev[j-1] + prev[j];
                }else {
                  curr[j] = prev[j];
                }
            }
        }
        return (int)prev[n];
    }
};