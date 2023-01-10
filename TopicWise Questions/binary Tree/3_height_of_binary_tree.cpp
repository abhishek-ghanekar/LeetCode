class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // base case
        if(node == NULL) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight,rightHeight)+1;
    }
};