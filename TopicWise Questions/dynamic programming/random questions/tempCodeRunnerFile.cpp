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