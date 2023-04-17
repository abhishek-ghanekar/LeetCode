// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/solutions/?orderBy=most_votes



class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = candies[0];
        int n = candies.size();
        for(int i=0;i<candies.size();i++) {
            if(candies[i] > max) {
                max = candies[i];
            }
        }

        //now we got the max
        vector<bool> ans(n);
        for(int i=0;i<n;i++) {
           if(candies[i] + extraCandies >= max) {
               ans[i] = true;
           }else {
               ans[i] = false;
           }
        }
        return ans;
    }
};