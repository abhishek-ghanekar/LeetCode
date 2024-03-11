#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> pfnc(string s) {
    // we need to form the pi vector
    //  a b c d a b c d
    int n = s.size();
    vector<int> pi(n,0);
    pi[0] = 0;
    for(int i=1;i<n;i++) {
        // the 
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]) {
            j = pi[j-1];
            j--;
        }
        if(s[i] == s[j]) {
            // we found something that is equal 
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
int main()
{
    string s = "abcdabcda";
    vector<int> res = pfnc(s);
    for(auto it:res) cout << it << " ";
    return 0;
}