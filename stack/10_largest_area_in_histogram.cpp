class Solution {
private:
    vector<int> nextSmallerIndex(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n);
    stack<int> s;

    s.push(-1);
    for(int i=n-1;i>=0;i--) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    } 
    
    return ans;
}
vector<int> prevSmallerIndex(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n);
    stack<int> s;

    s.push(-1);
    for(int i=0;i<n;i++) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    } 
    
    return ans;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerIndex(heights,n);

        vector<int> prev(n);
        prev = prevSmallerIndex(heights,n);
        int area = INT_MIN;
        for(int i=0;i<n;i++) {
            int length = heights[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            int breadth = next[i] - prev[i] - 1;
            int newArea = length * breadth;
            area = max(area,newArea);
        }
        return area;
    }
};