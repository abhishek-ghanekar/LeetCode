class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long ans = 0;
        priority_queue <long long, vector<long long>, greater<long long> > pq;
        for(int i=0;i<n;i++) {
            pq.push(arr[i]);
        }
        while(pq.size() > 1) {
            long long a1 = pq.top();
            pq.pop();
            long long a2 = pq.top();
            pq.pop();
            long long sum = a1 + a2;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};