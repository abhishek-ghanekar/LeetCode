class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL) {
    	    return result;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	while(!q.empty()) {
    	    int size = q.size();
    	    vector<int> row(size);
    	    for(int i=0;i<size;i++) {
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        int index = leftToRight ? i : size - i - 1;
    	        row[index] = frontNode->data;
    	        if(frontNode->left) {
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right) {
    	            q.push(frontNode->right);
    	        }
    	    }
    	    leftToRight = !leftToRight;
    	   // result.push_back(row);
    	    for(int i=0;i<row.size();i++) {
    	        result.push_back(row[i]);
    	    }
    	}
    	return result;
    }
};