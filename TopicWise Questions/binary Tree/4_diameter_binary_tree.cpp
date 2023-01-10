//find the diameter of the binary tree
//in this solution we get the answer using o(n2);
class Solution {
  private:
  int height(Node* root){
      if(root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight,rightHeight)+1;
  }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL) {
            return 0;
        }
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;
        int ans = max(op1 , max(op2,op3));
        return ans;
    }
};
// Optimized Solution
class Solution {
  private:
  pair<int,int> diameterFast(Node* root) {
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second) + 1;
    return ans;
}
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
    return diameterFast(root).first;
    }
    
};