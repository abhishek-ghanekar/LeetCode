void inorder(TreeNode<int>* root,vector<int> &ans) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    inorder(root,ans);

    TreeNode<int>* newRoot = new TreeNode<int>(ans[0]);

    TreeNode<int>* curr = newRoot;
    for(int i=1;i<ans.size();i++) {
        TreeNode<int>* temp = new TreeNode<int>(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    return newRoot;
}

//optimal approach
#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void bstToDll(TreeNode<int>* root,TreeNode<int>* &head) {
    if(root == NULL) {
        return ;
    }

    bstToDll(root->right,head);
    root->right = head;
    if(head != NULL) {
        head->left = root;
    }

    head = root;
    bstToDll(root->left,head);
}
TreeNode<int>* mergeLl(TreeNode<int>* head1,TreeNode<int>* head2) {
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    while(head1 != NULL && head2 != NULL) {
     if(head1->data < head2->data) {
        if(head == NULL) {
            head = head1;
            tail = head1;
            head1 = head1->right;
        }else {
           tail->right = head1;
           head1->left = tail;
           tail = head1;
           head1 = head1->right;
           
        }
      }else {
       if(head == NULL) {
            head = head2;
            tail = head2;
            head2 = head2->right;
        }else {
        tail->right = head2;
           head2->left = tail;
           tail = head2;
           head2 = head2->right;
           
        }
      }
    }
    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
    
}
TreeNode<int>* sortedLlToBst(TreeNode<int>* &head,int n) {
    if(n<=0 || head == NULL) {
        return NULL;
    }
    TreeNode<int>* left = sortedLlToBst(head,n/2);

    TreeNode<int>* root = head;
    root->left = left;

    head = head->right;
    TreeNode<int>* right = sortedLlToBst(head,n-n/2-1);
    root->right = right;

    return root;
}
int countNode(TreeNode<int>* head) {
    int count = 0;
    
    while(head != NULL) {
        count++;
        head = head->right;
    }
    return count;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    TreeNode<int>* head1 = NULL;
    bstToDll(root1,head1);
    TreeNode<int>* head2 = NULL;
    bstToDll(root2,head2);

    TreeNode<int>* merged = mergeLl(head1,head2);
    return sortedLlToBst(merged,countNode(merged));

}