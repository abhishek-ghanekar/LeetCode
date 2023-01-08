// question 1 : 2529. Maximum Count of Positive Integer and Negative Integer
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = 0;
        int posCount = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] < 0) {
                negCount++;
            }else if(nums[i] > 0) {
                posCount++;
            }
        }
        return max(negCount,posCount);
    }
};
// question 2 : 2530. Maximal Score After Applying K Operations
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(),nums.end());
        while(k--) {
            long long temp = pq.top();
            ans += temp;
            
            pq.pop();
            pq.push((temp+2)/3); // this is the ceil value
        }
        return ans;
    }
};