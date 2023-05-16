bool f(int n,int k,vector<int> &arr) {
  vector<bool> prev(k+1,false),curr(k+1,false);
  prev[0] = true;
  curr[0] = true;
  prev[arr[0]] = true;
  for(int i=1;i<n;i++) {
    for(int target = 1; target <= k;target++) {
      bool notPick = prev[target];
      bool pick = false;
      if(arr[i] <= target) pick = prev[target-arr[i]];
      curr[target] = pick || notPick;
    }
    prev = curr;
  }
  return prev[k];
  
  
}
bool canPartition(vector<int> &arr, int n)
{
	// we need to divide the array into two parts such that thier sum is equal to each other
  int sum = 0 ;
  for(auto i:arr) sum += i;
  //if the sum cant be divided into two parts then return false
  if(sum%2 == 1) return false;
  // we need to find a subarray whose sum is equal to s/2
  return f(n,sum/2,arr); 
}
