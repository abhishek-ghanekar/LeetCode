#include <bits/stdc++.h> 
int solve(int idx,vector<int> &heights,vector<int> &dp) {
    if(idx == 0) return 0;
    vector<int> temp;
    for(int i = idx ; i> 0 ; i--) {
        if(idx - i +1 > 0) {
           int num = solve(idx - i + 1);
           temp.push_back(num);
        }
    }
    sort(temp.begin(),temp.end());
    return temp[0];
}
int frogJump(int n, vector<int> &heights)
{
    //using memoization
    //converting this into dp
    vector<int> dp(n+2,-1);
    return solve(n-1,heights,dp);
    

}