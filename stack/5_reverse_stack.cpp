//reverse stack using recursion
void insert(stack<int> &s,int x){
    if(s.empty()) {
        s.push(x);
        return ;
    }
    int num = s.top();
    s.pop();
    insert(s,x);
    s.push(num);
}
void reverse(stack<int> &s) {
    if(s.empty()) {
        return ;
    }
    int num = s.top();
    s.pop();
    //recrusive call
    reverse(s);
    //
    insert(s,num);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    reverse(stack);
}