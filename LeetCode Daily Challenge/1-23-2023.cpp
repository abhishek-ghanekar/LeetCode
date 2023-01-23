class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> whoKnowsWho(n+1,0);
        if(n==1) {
            return 1;
        }
        for(int i=0;i<trust.size();i++) {
            whoKnowsWho[trust[i][0]]--;
            whoKnowsWho[trust[i][1]]++;
        }
        for(int i=0;i<whoKnowsWho.size();i++) {
            if(whoKnowsWho[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};