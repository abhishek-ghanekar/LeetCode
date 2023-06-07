class Solution {
private:
    int getCost(int i,int j,vector<int> &cuts) {
        // base case
        if(i > j) return 0;
        // if(i == j) return 1;
        int cost = 1e9;
        for(int k=i;k<j;k++) {
            // try all partitions
           int  val = cuts[j+1] - cuts[i-1] + getCost(i,k-1,cuts) + getCost(k+1,j,cuts);
            cost = min(cost,val);
        }
        return cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        return getCost(1,cuts.size()-2,cuts);
    }
};