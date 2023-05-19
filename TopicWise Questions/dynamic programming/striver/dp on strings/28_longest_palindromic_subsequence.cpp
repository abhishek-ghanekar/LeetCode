class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(s[i] == t[j]) {
                    if(i==0 || j==0) {
                        curr[j] = 1;
                    }else {
                        curr[j] = 1 + prev[j-1];
                    }
                }else {
                    int val1 = 0;
                    int val2 = 0;
                    if(i>0) val1 = prev[j];
                    if(j>0) val2 = curr[j-1];
                    curr[j] = max(val1,val2);
                }
            }
            prev = curr;
        }
        return  prev[n-1];
    }
};