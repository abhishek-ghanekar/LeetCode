Node * uniqueSortedList(Node * head) {

    Node* current = head;
    if(head == NULL) {
        return NULL;
    }
    while(current->next != NULL) {
        if(current->data == current->next->data) {
            Node* nodeToDelete = current -> next;
            delete(nodeToDelete);
            current->next = current->next->next;
        }else {
            current = current -> next;
        }
    }
    return head;
}