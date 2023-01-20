class Solution {
    //using a set as we dont want any repeated results
    set<vector<int>> result;
    vector<int> temp;
    void backTrack(vector<int> &nums,int index) {
        //base case
        if(index == nums.size()) {
            //if the temp size is greater than 2 then we insert into answer, we dont need to check any other 
            // condition as we have inserted based on that condition itself
            if(temp.size() >= 2) {
               result.insert(temp);
            }
            return;
        }
        //calling for including the value i.e left call
        //there can be two cases , either temp is empty or temp is not empty
        // we need to insert values when temp is empty or temp's back is less than the nums[index]
        if(temp.empty() || temp.back() <= nums[index]) {
            temp.push_back(nums[index]);
            backTrack(nums,index+1);
            temp.pop_back();
        }
        //calling for not including the value i.e the right call
        backTrack(nums,index+1);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTrack(nums,0);
        //changing the set into a vector
        return vector(result.begin(),result.end());
    }
};