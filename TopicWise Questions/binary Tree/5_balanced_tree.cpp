class Solution{
    private:
    pair<bool,int> balance(Node *root) {
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        pair<int,int> left = balance(root->left);
        pair<int,int> right = balance(root->right);
        
        bool leftbool = left.first;
        bool rightbool = right.first;
        bool diff = abs(left.second - right.second) <= 1;
        pair<bool,int> ans;
        ans.first = leftbool && rightbool && diff;
        ans.second = max(left.second,right.second) + 1;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return balance(root).first;
        
    }
};