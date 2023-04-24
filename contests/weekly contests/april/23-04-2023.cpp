// https://leetcode.com/contest/weekly-contest-342/
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int ans = 0;
        ans = arrivalTime+delayedTime;
        return ans%24;
    }
};


class Solution {
public:
    int sumOfMultiples(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if((i%3 == 0) || (i%5 ==0) || (i%7 ==0)) {
                ans += i;
            }
        }
        return ans;
    }
};