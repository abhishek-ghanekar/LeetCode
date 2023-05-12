#include <limits.h>
int f(int day, int lastChosen,vector<vector<int>> &points,vector<vector<int>> &memo) {
    if(day == 0) {
        int maxi = INT_MIN;
        for(int i=0;i<3;i++){
           if(i != lastChosen) {
               maxi = max(maxi,points[day][i]);
           }
        }
        return maxi;
    }
    if(memo[day][lastChosen] != -1) return memo[day][lastChosen];
        int maxi = 0;
        
        for(int i=0;i<3;i++) {
            if(i != lastChosen) {    
   int  pointsObtained = points[day][i] + f(day-1,i,points,memo); 
   maxi = max(maxi,pointsObtained);
            }
            
        }
        return memo[day][lastChosen] = maxi;
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> memo(n,vector<int>(4,-1));
    return f(n-1,3,points,memo);   
}



//tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    //we go bottom to top
    // do the process for all days
    for(int day=1;day<n;day++) {
        for(int last=0;last<=3;last++) {
            dp[day][last] = 0;
            for(int task=0;task < 3;task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}


//space optimization solution
int ninjaTraining(int n, vector<vector<int>> &points)
{

    //space optimized solution
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int day=1;day<n;day++) {
        vector<int> temp(4);
        for(int last=0;last<=3;last++) {
            temp[last] = 0;
            for(int task=0;task < 3;task++) {
                if(task != last) {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last],point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
    
}