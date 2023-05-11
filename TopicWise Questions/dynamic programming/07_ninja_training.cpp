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