int pos(int in[], int start , int end , int key){
            for(int i=start; i<=end;i++)
                if(in[i] == key)
                    return i;
                    
            return -1;
        }
Node* solve(int in[],int post[],int &index,int instart,int inend,int n) {
    if(instart > inend || index < 0) {
        return NULL;
    }
    int element = post[index];
    index--;
    
    Node* root = new Node(element);
    int position = pos(in,instart,inend,element);
    
    root->right = solve(in,post,index,position+1,inend,n);
    root->left = solve(in,post,index,instart,position-1,n);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1;
    
    Node* ans = solve(in,post,postOrderIndex,0,n-1,n);
    
    return ans;
}