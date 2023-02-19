void mirrorTree(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return ;
    }
    mirrorTree(root->left);
    mirrorTree(root->right);
    BinaryTreeNode<int>* left = root->left;
    BinaryTreeNode<int>* right = root->right;

    root->left = right;
    root->right = left;

}