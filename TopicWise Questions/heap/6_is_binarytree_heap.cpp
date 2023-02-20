
class Solution {
  public:
    int countNodes(struct Node* tree) {
        if (tree == NULL) {
        return 0;
    }
    int leftCount = countNodes(tree->left);
    int rightCount = countNodes(tree->right);
    return 1 + leftCount + rightCount;
        
    }
    bool isComplete(struct Node* tree,int index,int nodeCount) {
        if(tree == NULL) {
            return true;
        }
        
        if(index >= nodeCount) {
            return false;
        }else {
            bool left = isComplete(tree->left,2*index+1,nodeCount);
            bool right = isComplete(tree->right,2*index+2,nodeCount);
            return (left && right);
        }
        
    }
    bool isMax(struct Node* tree) {
        
        if(tree->left == NULL && tree->right == NULL) {
            return true;
        }
        if(tree->right == NULL) {
            return (tree->data > tree->left->data);
        }else {
            bool left = isMax(tree->left);
            bool right = isMax(tree->right);
            return (tree->data > tree->left->data && tree->data > tree->right->data) && left && right;
        }
    
    }
    bool isHeap(struct Node* tree) {
        
        
        int index = 0;
        return isComplete(tree,index,countNodes(tree)) && isMax(tree); 
        
    }
};