#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr,int mid,int c) {
    int cows = 1;
    int lastPos = arr[0];
    for(int i=0;i<arr.size();i++) {
        if(arr[i] - lastPos >= mid) {
            cows++;
            lastPos = arr[i];
        }
        if(cows >= c) return true;
    }
    return false;
}
void solve() {
    int n,c;
    cin >> n >> c;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    // we got the input
    sort(arr.begin(),arr.end());
    int start = 1;
    int end = arr[n-1] - arr[0];
    int ans = -1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(isPossible(arr,mid,c)) {
            ans = mid;
            start = mid+1;
        }else {
           end = mid-1;
        }
    }
    cout << ans << endl;
    
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}