#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++) {
      if(s[i] == '('  || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
          st.push(s[i]);
      }else {
          //closing bracket of lowercase
          if(s[i] == ')') {
              bool isReduncdant = true;
              while(st.top() != '(') {
                  char top = st.top();
                  if(top == '*' || top == '/' || top == '+' || top == '-') {
                      isReduncdant = false;
                  }
                  st.pop();
              }
              if(isReduncdant == true) {
                  return true;
              }
              st.pop();
          }
      }
    }
    return false;
}
