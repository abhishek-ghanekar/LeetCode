class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i:stones) {
            pq.push(i);
        }
        while(pq.size() > 1) {
            int p = pq.top();
            pq.pop();
            int q = pq.top();
            pq.pop();
            if(p > q) {
                pq.push(p-q);
            }
        }
        if(pq.empty()) {
          return 0;
        }else {
          return pq.top();
        }
        // we can also write this as pq.empty() ? 0 : pq.top();
        
    }
};