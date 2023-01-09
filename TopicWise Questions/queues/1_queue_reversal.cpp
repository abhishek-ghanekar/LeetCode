//function Template for C++
void reverse(queue<int> &q) {
    if(q.empty()) {
        return ;
    }
    
    int val = q.front();
    q.pop();
    reverse(q);
    q.push(val);
}
//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    // queue<int> ans;
    // stack<int> temp;
    // while(!q.empty()) {
    //     temp.push(q.front());
    //     q.pop();
    // }
    
    // while(!temp.empty()) {
    //     int val = temp.top();
    //     q.push(val);
    //     temp.pop();
    // }
    // return q;
    
    
    //base condition
    reverse(q);
    return q;
}