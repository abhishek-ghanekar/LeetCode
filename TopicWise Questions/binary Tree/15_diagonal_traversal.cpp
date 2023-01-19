//diagonal traversal
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        // ans.push_back(front->data);
        while(front) {
            if(front->left) {
                q.push(front->left);
            }
            ans.push_back(front->data);
            front = front->right;
        }
    }
    return ans;
}