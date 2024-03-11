#include <bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    // int i = 0;
    // int j = 0;
    // map<char,int> mp;
    // int n = s.size();
    // int ans = -1;
    // int count = 0;
    // while(j < n) {
    //   mp[s[j]]++;
    //   if(mp[s[j]] == 1) count++; 
    //   if(count < k) {
    //     j++;
    //   }else if(count == k) {
    //       // we got the window
    //       ans = max(ans,j-i+1);
    //       j++;
    //   }else {
    //       while(count > k) {
    //           // while the size is greater
    //           mp[s[i]]--;
    //           if(mp[s[i]] == 0) {
    //               count--;
    //           }
    //           i++;
    //       }
    //       j++;
    //   }
    // }
    // return ans;
    int i=0, j=0;
    int n = s.length();

    map<char, int> mp;

    int count = 0;
    int ans = -1;

    while(j<n){
        mp[s[j]]++;
        if(mp[s[j]] == 1) count++;
        if(count <= k){
            ans = max(ans,j-i+1);
            j++;
        }else{
            while(count > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) count--;
                i++;
            }
            j++;
        }
    }

    return ans;
}