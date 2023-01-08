#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
private:
    long long  findMax(vector<int>& nums) {
        long long max = nums[0];
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > max ) {
                max = nums[i];
            }
        }
        return max;
    }
public:
    long long maxKelements(vector<int>& nums, int k) {
        // int cnt = 0;
        long long temp;
        long long temp2;
        long long ans = 0;
        for(int i=0;i<k;i++) {
            temp = findMax(nums);
            temp2 = ceil(temp/3);
            ans += temp;
            int index = distance(nums.begin(), find(nums.begin(),nums.end(),temp));
            nums[index] = temp2;
        }
        return ans;
    }
};
int main() {
    vector<int> nums;
    nums.push_back();
    nums.push_back();
    return 0;
}


#include <algorithm>
class Solution {
private:
    long long  findMax(vector<int>& nums) {
        long long max = nums[0];
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > max ) {
                max = nums[i];
            }
        }
        return max;
    }
public:
    long long maxKelements(vector<int>& nums, int k) {
        // int cnt = 0;
        long long temp;
        long long temp2;
        long long ans = 0;
        for(int i=0;i<k;i++) {
            temp = findMax(nums);
            temp2 = ceil(temp/3);
            ans += temp;
            int index = distance(nums.begin(), find(nums.begin(),nums.end(),temp));
            nums[index] = temp2;
        }
        return ans;
    }
};