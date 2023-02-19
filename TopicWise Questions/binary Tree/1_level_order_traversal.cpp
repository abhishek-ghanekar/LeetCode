class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                int index = i;
                row[index] = frontNode->val;
                if(frontNode->left) {
                    q.push(frontNode->left);
                }
                if(frontNode->right) {
                    q.push(frontNode->right);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};