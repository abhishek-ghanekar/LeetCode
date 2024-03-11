#include<iostream>
#include<vector>
using namespace std;
int bruteForce(vector<int> arr,int n) {
    int sum = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
          sum += (arr[i] ^ arr[j]);
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    // we have gotten the array
    cout << "the total sum of all pair xor is " << bruteForce(arr,n);
    return 0;
}