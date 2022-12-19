// Find the Middle Node of the Linked List Approach 1
class Solution {
    private:
    int getLength(Node *head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
    }
    public:
    Node *findMiddle(Node *head) {
    int len = getLength(head);
    int mid = (len/2) + 1;
    Node *temp = head;
    int cnt = 0;
    while(cnt < mid-1) {
        temp = temp->next;
        cnt++;
    }
    return temp;
}
}
//  Approach 2 (fast and slow runner approach)
class Solution {
    public:
    Node* getMiddle(Node* &head) {
    if((head == NULL)||(head->next == NULL)) {
        return head;
    }
    if(head->next->next == NULL) {
        return head->next;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next; 
    }
    return slow;
    }
}