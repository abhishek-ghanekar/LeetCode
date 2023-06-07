class Solution {
private:
    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &memo) {
        if(i > j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int maxi = -1e9;
        for(int k=i;k<=j;k++) {
           // we have to think in the opposite way that what will be the last balloon to burst
           int val = nums[k] * nums[i-1] * nums[j+1] + solve(i,k-1,nums,memo) + solve(k+1,j,nums,memo);
           maxi = max(val,maxi);
        }
        return memo[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> memo(nums.size(),vector<int>(nums.size(),-1));
        return solve(1,nums.size()-2,nums,memo);
    }
};