#include <iostream>
#include <queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
       this->data = d;
       this->right = NULL;
       this->left = NULL;
    }
};
Node* minVal(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* maxVal(Node* root) {
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}
Node* insertToBst(Node* &root,int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertToBst(root->right,data);
       
    }else {
        root->left = insertToBst(root->left,data);
    }
    return root;
}
void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1) {
        root = insertToBst(root,data);
        cin >> data;
    }
}
Node* deleteFromBst(Node* root,int val) {
    //0 child
    if(root == NULL) {
        return root;
    }
    if(root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    //1child
    if(root->data == val) {
        if(root->left != NULL && root->right == NULL) {
       Node* temp = root->left;
       delete root;
       return temp;
    }

    if(root->left == NULL && root->right != NULL) {
       Node* temp = root->right;
       delete root;
       return temp;
    }
    //2child
    if(root->left != NULL && root->right != NULL) {
        int mini = minVal(root->right) ->data;
        root->data = mini;
        root->right = deleteFromBst(root->right,mini);
        return root;
    }
    }else if(val > root->data) {
        root->right = deleteFromBst(root->right,val);
    }else {
        root->left = deleteFromBst(root->left,val);
    }
    
}
void levelOrderTraversal(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if(temp == NULL) {
                cout << endl;
                if(!q.empty()) {
                    q.push(NULL);
                }
            }else {
                cout << temp->data << " ";
                if(temp->left != NULL) {
                q.push(temp->left);
               }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
}
int main()
{
    Node* root = NULL;
    cout << "enter the input" << endl;
    takeInput(root);
    cout << "printing the tree we get" << endl;
    levelOrderTraversal(root);
    deleteFromBst(root,30);
    cout << endl;
    levelOrderTraversal(root);
    return 0;
}