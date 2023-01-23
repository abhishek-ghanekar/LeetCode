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
    return 0;
}