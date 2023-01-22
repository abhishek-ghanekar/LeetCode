class Solution {
  public:
    Node* createMapping(Node* root,int target,map<Node*,Node*> &nodeToParent) {
        Node* res = NULL;
        queue<Node*> q;
        nodeToParent[root] = NULL;
        q.push(root);
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if(front->data == target) {
                res = front;
            }
            if(front->left) {
                q.push(front->left);
                nodeToParent[front->left] = front;
            }
            if(front->right) {
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
        }
        return res;
    }
    int burn(Node* root,map<Node*,Node*> &nodeToParent) {
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;
        int ans = 0;
        while(!q.empty()) {
            int size = q.size();
            bool flag = 0;
            for(int i=0;i<size;i++) {
                Node* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag == 1) {
                    ans++;
             }
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createMapping(root,target,nodeToParent);
        return burn(targetNode,nodeToParent);
    }
};
