class Solution
{
    private:
    void insertAtTail(Node* &head,Node* &tail,int value) {
        Node* temp = new Node(value);
        if(head == NULL) {
            head = temp;
            tail = temp;
            return ;
           
        }else {
            tail->next = temp;
            tail = temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //traverse thru the list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        unordered_map<Node*,Node*> values;
        
        while(temp) {
            //copy into new list
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }
        temp = head;
        Node* temp2 = cloneHead;
        while(temp2 && temp) {
            values[temp] = temp2;
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        temp = head;
        temp2 = cloneHead;
        while(temp) {
            
            temp2 -> arb = values[temp->arb];
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        
        return cloneHead;
    }

};