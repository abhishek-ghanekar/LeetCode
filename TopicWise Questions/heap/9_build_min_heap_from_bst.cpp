void inorder(BinaryTreeNode* root,vector<int> &in) {
	if(root == NULL) {
		return ;
	}
	inorder(root->left,in);
	in.push_back(root->data);
	inorder(root->right,in);
}
BinaryTreeNode* convertHelper(BinaryTreeNode* &root,vector<int> in,int &index) {
    if(root == NULL) {
		return NULL;
	}

	root->data = in[index++];
	convertHelper(root->left,in, index);
    convertHelper(root->right,in, index);
	return root;
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> in;
	inorder(root,in);
	int index = 0;
	
	return convertHelper(root,in,index);
}