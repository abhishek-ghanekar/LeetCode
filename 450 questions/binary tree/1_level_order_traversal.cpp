class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      queue<Node*> q;
      q.push(node);
      vector<int> ans;
      while(!q.empty()) {
          Node* frontNode = q.front();
          q.pop();
          ans.push_back(frontNode->data);
          if(frontNode->left) {
              q.push(frontNode->left);
          }
          
          if(frontNode->right) {
              q.push(frontNode->right);
          }
          
      }
      return ans;
    }
};