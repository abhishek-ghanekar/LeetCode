bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    for(int i=0;i<expression.length();i++) {
        char ch = expression[i];
        if(ch == '[' || ch == '(' || ch == '{') {
            s.push(ch);
        }else {
            if(!s.empty()) {
                if((ch == ')' && s.top() == '(')||(ch==']' && s.top() == '[')||(ch=='}' && s.top() == '{')) {    
                    s.pop();
                }else {
                    return false;
                }
            }else {
                return false;
            }
        }
    }
    return s.empty();
}