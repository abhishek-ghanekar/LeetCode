// Problem Statement

// Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

// Input Format
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

// Sample Input
// 4

// [
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
// ]

// Sample Output
// 13

// Constraints
// N <= 20
#include<iostream>
#include<vector>
#include <limits>
#include <bits/stdc++.h>
using namespace std;
int getMinCost(int i,int mask,int n,vector<vector<int>> cost) {
    if(i == n+1 ) return 0;
    int minCost = INT_MAX;
    for(int j=0;j<=n-1;j++) {
        if((mask & (1 << j)) == 0) {
            int val = cost[i][j+1] + getMinCost(i+1,(mask^(1<<j)),n,cost);
            minCost = min(minCost,val);
        }
    }
    return minCost;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cost(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> cost[i][j];
        }
    }

    // now we have both cost and person/job;
    cout << getMinCost(1,0,n,cost);
    return 0;
}