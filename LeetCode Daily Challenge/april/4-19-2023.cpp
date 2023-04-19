// my solution
// class Solution {
// public:
//     int longestZigZag(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         int ans = 0; 
//         while(!q.empty()) {
//             TreeNode* temp = q.front();
//             q.pop();
//             int leftAns = 0;
//             int rightAns = 0;
//             if(temp->left) {
//               q.push(temp->left);
//               TreeNode* temp1 = temp;
//               bool flag1 = true;
              
//               while(true) {
//                 if(flag1) {
//                     if(temp1->left) {
//                         temp1 = temp1->left;
//                     }else {
//                         break;
//                     }
//                 }else {
//                     if(temp1->right) {
//                        temp1 = temp1->right;
//                     }else {
//                         break;
//                     }
//                 }
//                 flag1 = !flag1;
//                 leftAns++;
//               }
//             }
//             if(temp->right) {
//               q.push(temp->right);
//               TreeNode* temp2 = temp;
//               bool flag2 = false;
              
//               while(true) {
//                 if(flag2) {
//                     if(temp2->left) {
//                         temp2 = temp2->left;
//                     }else {
//                         break;
//                     }
//                 }else {
//                     if(temp2->right) {
//                        temp2 = temp2->right;
//                     }else {
//                         break;
//                     }
//                 }
//                 flag2 = !flag2;
//                 rightAns++;
//               }
//             }
//             int tempMax = max(leftAns,rightAns);
//             ans = max(ans,tempMax);
//         }
//         return ans;
//     }
// };
//correct answer
class Solution {
public:
    int res = 0;
    void solve(TreeNode* root, bool goLeft, int curr) {
        if(!root) return ;
        res = max(res,curr);
        if(goLeft) {
           solve(root->left,false,curr+1);
           solve(root->right,true,1);
        }else {
            solve(root->left,false,1);
            solve(root->right,true,curr+1);
            
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root,true,0);
        solve(root,false,0);
        return res;
    }
};
