
// your task is to complete this function
Node* solve(Node* root,int &k,int node) {
    //base case
    if(root == NULL) {
        return NULL;
    }
    if(root->data == node) {
        return root;
    }
    
    Node* leftAns = solve(root->left,k,node);
    Node* rightAns = solve(root->right,k,node);
    if(leftAns != NULL && rightAns == NULL) {
        if(k>=0) {
            k--;
            if(k==0) {
                k = INT_MAX;
                return root;
            }
            
        }
        return leftAns;
    }
    if(leftAns ==NULL && rightAns != NULL) {
        if(k>=0) {
            k--;
            if(k==0) {
                k = INT_MAX;
                return root;
            }
        }
        return rightAns;
    }
    return NULL;
    
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root,k,node);
    if(ans == NULL || ans->data == node) {
        return -1;
    }else {
        return ans->data;
    }
}
