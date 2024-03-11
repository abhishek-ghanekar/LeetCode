#include<iostream>
#include<vector>
using namespace std;
int bruteForce(vector<int> arr,int n) {
    int temp = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
           int sum = arr[i] + arr[j];
           temp = temp ^ sum;
        }
    } 
    return temp;
}
int optimal(vector<int> arr,int n) {
    int temp = 0;
    for(int i=0;i<n;i++) {
        temp = temp ^ (arr[i] + arr[i]);
    }
    return temp;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    // now we got the array
    
    cout << endl;
    cout << "the all pair xor pair sum is " << bruteForce(arr,n) << endl;
    cout << "the all pair xor pair sum is " << optimal(arr,n);
    return 0;
}