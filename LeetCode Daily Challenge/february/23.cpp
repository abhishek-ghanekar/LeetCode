class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for(int i=0;i<n;i++) {
            projects[i] = {capital[i],profits[i]};
        }

        //we sort so we can make sure that profit 

        sort(projects.begin(),projects.end());
 
        int i = 0;
        priority_queue<int> maximizeCapital;
        // do while k days
        while(k--) {
            //this will make sure the max element gets pushed
            while(i<n && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if(maximizeCapital.empty()) {
                break;
            }
            // by selecting the top we make sure to always select the maximum 
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};