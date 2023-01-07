class Solution
{
    private:
    struct Node* reverse(struct Node* &head) {
        Node* previous = NULL;
        Node* current = head;
        Node* forward;
        while(current != NULL) {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
    return previous;
    }
    void insertAtTail(struct Node* &head,struct Node* &tail,int d) {
        Node* temp = new Node(d);
        if(head == NULL) {
            head = temp;
            tail = temp;
            return ;
        }else {
            tail->next = temp;
            tail = temp;
        }
    }
    struct Node* add(struct Node* &first,struct Node* &second) {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        while(first && second) {
            int sum = carry + first->data + second->data;
            int digit = sum%10;
            // Node* temp = new Node(digit);
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            first = first -> next;
            second = second -> next;
        }
        while(first) {
            int sum = carry + first->data;
            int digit = sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            first = first -> next;
        }
        while(second) {
            int sum = carry + second->data;
            int digit = sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            second = second -> next;
        }
        while(carry) {
            int sum = carry;
            int digit = sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        Node* ans = add(first,second);
        
        //reverse the answer
        ans = reverse(ans);
        return ans;
    }
};
