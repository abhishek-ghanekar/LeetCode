bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }
    if(root->data == x) {
        return true;
    }
    if(x>root->data) {
        searchInBST(root->right,x);
    }else {
        searchInBST(root->left,x);
    }
}