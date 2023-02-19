#include <bits/stdc++.h> 
#include <algorithm>
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class info {
   public:
    int mini;
    int maxi;
    bool isBst;
    int size;
};
info solve(TreeNode<int>* root,int &ans) {
    if(root == NULL) {
        info ans;
        ans.mini = INT_MAX;
        ans.maxi = INT_MIN;
        ans.size = 0;
        ans.isBst = true;
        return ans;
    }
    info leftSubtree = solve(root->left,ans);
    info rightSubtree = solve(root->right,ans);

    info curr;
    curr.size = leftSubtree.size + rightSubtree.size + 1;
    curr.mini = min(root->data,leftSubtree.mini);
    curr.maxi = max(root->data,rightSubtree.maxi);

    if(leftSubtree.isBst && rightSubtree.isBst && (root->data < rightSubtree.mini && root->data > leftSubtree.maxi)) {
        curr.isBst = true;
        
    }else {
        curr.isBst = false;
    }
    if(curr.isBst) {
        ans = max(ans,curr.size);
    }
    return curr;


}
int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    solve(root,maxSize);
    return maxSize;

}
