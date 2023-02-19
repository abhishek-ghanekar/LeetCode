bool isBst(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool left = sBst(root->left, min, root->data);
        bool right = isBst(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root)
{
    return isBst(root, INT_MIN, INT_MAX);
}

class info
{
public:
    int mini;
    int maxi;
    int sum;
    bool isBst;
};
class Solution
{
public:
    int maxSum = 0;
    info solve(TreeNode *root)
    {
        if (root == NULL)
        {
            info ans;
            ans.mini = INT_MIN;
            ans.maxi = INT_MAX;
            ans.sum = 0;
            ans.isBst = true;
            return ans;
        }
        info left = solve(root->left);
        info right = solve(root->right);
        info curr;
        curr.mini = min(root->val, left.mini);
        curr.maxi = max(root->val, right.maxi);
        curr.sum = left.sum + right.sum + root->val;
        if ((left.isBst && right.isBst  ) && (root->val < right.mini && root->val > left.maxi))
        {
            curr.isBst = true;
            maxSum = max(maxSum, curr.sum);
        }
        else
        {
            curr.isBst = false;
        }
        return curr;
    }
    int maxSumBST(TreeNode *root)
    {
        solve(root);
        return maxSum;
    }
};