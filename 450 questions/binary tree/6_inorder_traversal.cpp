
//iterative method
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        vector<int> ans;
        while(true) {
            if(curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }else {
                if(s.empty() == true) {
                  break;
                }
                curr = s.top();
                s.pop();
                ans.push_back(curr->val);
                curr = curr->right;

            }
        }
        return ans;
    }
};