#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<string> getAns(vector<int> nums) {
   int i = 0 ;
   int n = nums.size();
   vector<string> ans;
   int j;
   while(i < n) {
      j = i;
      while( j < n - 1  && nums[j+1] == nums[j] + 1 ) {
        j++;
      }
      if(i == j) {
        ans.push_back(to_string(nums[i]));
      }else {
        ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
      }
      i = j + 1;
   }
   return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin >>  nums[i];
    }
    vector<string> hehe=  getAns(nums);
    for(auto i:hehe) {
        cout << i << " ";
    }
    return 0;
}