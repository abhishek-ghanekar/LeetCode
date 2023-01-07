class Solution {
private:
    bool check(vector<int> v) {
        int n = v.size();
        int s = 0;
        int e = n-1;
        while(s<=e) {
            if(v[s] != v[e] ) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp) {
            v.push_back(temp->val);
            temp = temp -> next;
        }
        return check(v);
    }
};