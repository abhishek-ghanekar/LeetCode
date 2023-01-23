//morris traversal is used to traverse the tree in constant space complexity
//following is the code for inorder
Node* curr = root;

while(curr != NULL) {
   if(curr->left == NULL) {
    cout << curr->data << " ";
    curr = curr->right;
   }else {
    Node* pre = curr ->left;
    while(pre->right && pre->right != curr) {
        pre = pre->right;
    }
    if(pre->right == NULL) {
        pre->right = curr;
        curr = curr -> left;

    }else {
        pre->right = NULL;
        cout << curr->data << " ";
        curr = curr->right;
    }
    
   }
}