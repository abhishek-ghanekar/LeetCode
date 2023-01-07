// Algorithm For Merge Sort
// write base class
// divide the list in 2 parts
// find the mid of the list
//run a recursive call on both parts
//merge the parts
node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while(fast->next && fast->next->next) {
        slow = slow -> next;
        fast = fast->next->next;
    }
    return slow;
}
node* merge(node* first,node* second) {
    if(!first) {
        return second;
    }
    if(!second) {
        return first;
    }
    node* ansHead = NULL;
    node* ansTail = NULL;
    if(first->data < second->data) {
        ansHead = first;
        ansTail = first;
        first = first -> next;
    }else {
        ansHead = second;
        ansTail = second;
        second = second ->next;
    }
    
    while(first && second) {
        if(first->data < second->data) {
            ansTail->next = first;
            ansTail = first;
            first = first -> next;
        }else {
            ansTail->next = second;
            ansTail = second;
            second = second -> next;
        }
    }
    while(first) {
        ansTail->next = first;
        ansTail = first;
        first = first -> next;
    }
    while(second) {
        ansTail ->next = second;
        ansTail = second;
        second = second -> next;
    }
    return ansHead;
}
node* mergeSort(node *head) {
    if(head == NULL || head->next == NULL) {
       return head;
    }
    node* mid = findMid(head);
    node* half1 = head;
    node* half2 = mid->next;
    mid->next = NULL;
    half1 = mergeSort(half1);
    half2 = mergeSort(half2);
    node* ans = merge(half1,half2);
    return ans;
    
}