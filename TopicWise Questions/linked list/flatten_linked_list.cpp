Node* merge(Node* first,Node* second) {
    if(first == NULL) {
        return second;
    }
    if(second == NULL) {
        return first;
    }
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    if(first->data < second->data ) {
        ansHead = first;
        ansTail = first;
        first = first-> next;
    } else {
        ansHead = second;
        ansTail = second;
        second = second -> next;
    }
    while(first && second) {
        if(first->data < second->data) {
            ansTail->next = first;
            ansTail = first;
            first = first->next;
        }else {
            ansTail->next = second;
            ansTail = second;
            second = second->next;
        }
    }
    while(first) {
        ansTail->next = first;
        ansTail = first;
    }
    while(second) {
        ansTail->next = second;
        ansTail = second;
    }
    return ansHead;
    


}
Node* flatten(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    head->next = flatten(head->next);
    head = merge(head,head->next);
    return head;
}