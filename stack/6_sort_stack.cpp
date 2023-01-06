#include <bits/stdc++.h>
void insertSort(stack<int> &s,int n) {
    if(s.empty() || (!s.empty() && s.top() < n)) {
        s.push(n);
        return;
    }
    
        int num = s.top();
        s.pop();
        insertSort(s,n);
        s.push(num);
    
    }

void sortStack(stack<int> &stack)
{
	if(stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insertSort(stack,num);
}