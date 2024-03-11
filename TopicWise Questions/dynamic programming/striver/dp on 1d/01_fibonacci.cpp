#include<iostream>
#include <vector>
using namespace std;
Memoization
// int fibo(int n,vector<int> &dp) {
//     if(n <= 1) {
//         return n;
//     }
//     if(dp[n] != -1) {
//         return dp[n];
//     }
//     return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
// }
// int main()
// { 
//     vector<int> dp(10,-1);
//     cout << fibo(9,dp);
//     return 0;
// }
// #include<iostream>
// using namespace std;
using tabulation
int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n+1);
    int prev2 = 0;
    int prev = 1;,.3

    for(int i=2;i<=n;i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
    return 0;
}
