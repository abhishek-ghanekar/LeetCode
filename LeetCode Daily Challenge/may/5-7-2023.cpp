class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int count = 0;

        // a subsequence has 2^n possible combinations 
        // and if we get a vector which satisfies the answer then we must consider all the subsequences of the vector

        vector<int> powerOf2(nums.size(),1);
        powerOf2[0] = 1;
        for(int i=1;i<nums.size();i++) {
            powerOf2[i] = (2 * powerOf2[i-1])%mod;
        }
        // therefore we store a vector containing all the powers of 2
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                count += powerOf2[r-l];
                count = count%mod;
                l++;
            }else {
                r--;
            }
        }
        return count;
    }
};