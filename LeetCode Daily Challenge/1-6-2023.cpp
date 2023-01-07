// 1833. Maximum Ice Cream Bars
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i = 0;
        int cnt = 0;
        while(coins >= 0 && i<costs.size()) {
           if(costs[i] <= coins) {
               coins -= costs[i];
               cnt++;
           }
           i++;
        }
        return cnt;
    }
};