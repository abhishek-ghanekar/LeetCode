#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    // we need to fill in n rows
    ll dp[n+1];
    dp[0] = 1;
    dp[1] = 0;
    for(int i=2;i<=n;i++) {
        dp[i] = 2*dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}