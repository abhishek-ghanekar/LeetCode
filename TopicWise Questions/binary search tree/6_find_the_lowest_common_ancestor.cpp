
recursive method
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	//base case
    if(root == NULL) {
        return NULL;
    }

    if(root->data > P->data && root->data > Q->data) {
        LCAinaBST(root->left,P,Q);
    }else if(root->data < P->data && root->data < Q->data) {
        LCAinaBST(root->right,P,Q);
    }else {
        return root;
    }
}
//iterative method

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	while(root != NULL) {
        if(root->data > P->data && root->data > Q->data) {
            root = root->left;
        
    }else if(root->data < P->data && root->data < Q->data) {
        root = root->right;
        
    }else {
        return root;
    }
   }
   return NULL;
}