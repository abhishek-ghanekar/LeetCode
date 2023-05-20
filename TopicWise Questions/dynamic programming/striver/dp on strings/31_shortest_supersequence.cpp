// a supersequence is defined as a string that has both the strings as subsequences 
#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b)
{
	//first we need to compute the tabulation for the question
	int m = a.length();
	int n = b.length();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i-1] == b[j-1]) {
              dp[i][j] = 1 + dp[i-1][j-1];
			}else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	// now at index m and index n the length of the subsequence is stored
	int i = m;
	int j = n;
	string ans = "";
	while( i > 0 && j > 0 ) {
		if(a[i-1] == b[j-1]) {
			ans += a[i-1];
			i--;
			j--;
		}else if(dp[i-1][j] > dp[i][j-1]) {
           ans += a[i-1];
		   i--;
		}else {
			ans += b[j-1];
			j--;
		}
	}
	while(i>0){
       ans += a[i-1];
	   i--;
	} 
	while(j>0) {
		ans += b[j-1];
		j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}