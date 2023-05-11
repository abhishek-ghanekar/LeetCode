#include <bits/stdc++.h> 
int f(vector<int> &nums){
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i=1;i<n;i++) {
        int pick = nums[i] + prev2;
        int notPick = prev1;
        int curr = max(pick,notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    
    vector<int> temp1;
    vector<int> temp2;
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(int i=0;i<n;i++) {
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(f(temp1),f(temp2));
}