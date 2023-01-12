class Solution
{
    private: 
    pair<bool,int> sumTree(Node* root) {
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left == NULL && root->right == NULL) {
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        pair<bool,int> leftAnswer = sumTree(root->left);
        pair<bool,int> rightAnswer = sumTree(root->right);
        
        bool left = leftAnswer.first;
        bool right = rightAnswer.first;
        
        bool condition = root->data == leftAnswer.second + rightAnswer.second;
        pair<bool,int> ans;
        ans.first = left && right && condition;
        ans.second = 2*root->data;
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
        return sumTree(root).first;
        
    }
};