

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    int n = q.size();
    //add everything in the stack
    for(int i=0;i<k;i++) {
        int val = q.front();
        s.push(val);
        q.pop();
    }
    //remove from stack and put in the queue
    while(!s.empty()) {
        int val = s.top();
        q.push(val);
        s.pop();
    }
    
    //now remove the first n-k elements and put in the back
    for(int i=0;i<n-k;i++) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
    
}