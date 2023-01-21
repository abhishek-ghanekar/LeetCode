class Solution{
    public:
    // void createMapping(int in[],map<int,int> &nodeToIndex,int n) {
    //     for(int i=0;i<n;i++) {
    //         nodeToIndex[in[i]] = i ;
    //     }
        
    // }
    int findPosition(int in[],int inorderStart,int n,int element) {
        for(int i=inorderStart;i<n;i++) {
            if(in[i] == element) {
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int inorderStart,int inorderEnd,int &index,int n) {
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in,inorderStart,n,element);
        // int position = nodeToIndex[element];
        
        root->left = solve(in,pre,inorderStart,position -1,index,n);
        root->right = solve(in,pre,position+1,inorderEnd,index,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        
        int index = 0;
        // createMapping(in,nodeToIndex,n);
        Node* ans = solve(in,pre,0,n-1,index,n);
        return ans;
        
    }
};