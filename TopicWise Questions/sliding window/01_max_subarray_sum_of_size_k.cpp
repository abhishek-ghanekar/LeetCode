#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
       cin >> arr[i];
    }
    int i = 0;

    int j = 0;
    int maxi = INT_MIN;
    int sum = 0;
    while(j < n) {
        sum += arr[j];

        if(j-i+1 < k) {
            j++;
        }else if(j-i+1 == k) {
            maxi = max(maxi,sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    cout << maxi << endl;
    return 0;
}