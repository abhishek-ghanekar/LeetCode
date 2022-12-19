
// My Solution 
class Solution {
public:
    LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {

    LinkedListNode<int> *previous = NULL;
    LinkedListNode<int> *current = head;
    LinkedListNode<int> *forward;
    while(current != NULL) {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    return previous;
    } 
}
// optimal Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};