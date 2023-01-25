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
// iterative method 
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root != NULL) {
        if(root->data == x) {
            return true;
        }else if(x > root->data) {
            root = root->right;
        }else {
            root = root->left;
        }
    }
    return false;
}