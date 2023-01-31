void inorder(TreeNode<int>* root,vector<int> &in) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> mergeArray(vector<int> &a,vector<int> &b) {
    vector<int> ans(a.size()+b.size());
    int i =0 ;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()) {
        if(a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        }else {
            ans[k++] = b[j];
            j++;
        }
    }
    while(i<a.size()) {
        ans[k++] = a[i];
        i++;
    }
    while(j<b.size()) {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}
TreeNode<int>* inorderToBst(int s,int e,vector<int> in) {
    if(s>e) {
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);

    root->left = inorderToBst(s,mid-1,in);
    root->right = inorderToBst(mid+1,e,in);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> in1,in2;
    inorder(root1,in1);
    inorder(root2,in2);
    vector<int> ans = mergeArray(in1,in2);
    return inorderToBst(0,ans.size()-1,ans);
}