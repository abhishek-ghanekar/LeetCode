int findSmallest(BinaryTreeNode<int> *root,int k,int &i) {
    if(root == NULL) {
        return -1;
    }
    int left = findSmallest(root->left, k, i);
    if(left != -1) {
        return left;
    }

    i++;
    if(i == k) {
        return root->data;
    }

    int right = findSmallest(root->right,k,i);
    if(right != -1) {
        return right;
    }
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i =0;
    return findSmallest(root, k, i);

}