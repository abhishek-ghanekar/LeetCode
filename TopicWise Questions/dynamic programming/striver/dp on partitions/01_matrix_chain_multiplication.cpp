class Solution{
private:
    int solve(int i,int j,int arr[],vector<vector<int>> &dp) {
        if(i == j) return 0;
        // because no further operation can be done
        if(dp[i][j] != -1) return dp[i][j];
        int temp = 1e9;
        for(int k=i;k<j;k++) {
            int val = arr[k]*arr[i-1]*arr[j] + solve(i,k,arr,dp) + solve(k+1,j,arr,dp); 
            temp = min(temp,val);
        }
        return temp;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return solve(1,N-1,arr,dp);
    }
};