//using memoization

#include <bits/stdc++.h>
int f(int s1, int s2, string s, string t, vector<vector<int>> &memo) {
        if(s1<0||s2<0)return 0;
	if(memo[s1][s2] != -1) return memo[s1][s2];
        if(s[s1] == t[s2]) {
		//if the value is equal
		return memo[s1][s2] = 1 + f(s1-1,s2-1,s,t,memo);
	}else {
		// the value is not equal
		return memo[s1][s2] = max(f(s1-1,s2,s,t,memo),f(s1,s2-1,s,t,memo));
	}
}
int lcs(string s, string t)
{
	int m = s.length();
	int n = t.length();
	vector<vector<int>> memo(m,vector<int>(n,-1));
	return f(m-1,n-1,s,t,memo);
}

//using tabulation
#include <bits/stdc++.h>
int lcs(string s, string t)
{
	int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m,vector<int>(n,0));
    // check the base case
    //tabulation is always opposite to recursion
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(s[i] == t[j]) {
				if(i==0 || j==0) {
					dp[i][j] = 1;
				}else {
                    dp[i][j] = 1 + dp[i-1][j-1];
				}
            }else {
				int val1 = 0;
				int val2 = 0;
				if(i>0) val1 = dp[i-1][j];
				if(j>0) val2 = dp[i][j-1];
                dp[i][j] = max(val1,val2);
            }
        }
    }
    return dp[m-1][n-1];
}

// space optimization
#include <bits/stdc++.h>
int lcs(string s, string t)
{
	int n = s.length();
    int m = t.length();
    // vector<vector<int>> dp(m,vector<int>(n,0));
	vector<int> prev(m+1,0);
	vector<int> curr(m+1,0);
	// we will need two arrays prev and curr
    // check the base case
    //tabulation is always opposite to recursion
	for(int i=0;i<=m;i++) prev[i] = 0;
	// for(int j=0;j<=n;j++) dp[j][0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i-1] == t[j-1]) {
				curr[j] = 1 + prev[j-1];
            }else {
				curr[j] = max(prev[j],curr[j-1]);
            }
        }
		prev = curr;
    }
    return prev[m];
}