class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }
        if(!list2) {
            return list1;
        }

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        if(list1->val < list2->val) {
            ansHead = list1;
            ansTail = list1;
            list1 = list1->next;
        }else {
            ansHead = list2;
            ansTail = list2;
            list2 = list2 -> next;
        }
        while(list1 && list2) {
            if(list1->val < list2->val) {
                ansTail->next = list1;
                ansTail = list1;
                list1 = list1 -> next;
            }else {
                ansTail->next = list2;
                ansTail = list2;
                list2 = list2 ->next;
            }
        }
        while(list1) {
            ansTail->next = list1;
                ansTail = list1;
                list1 = list1 -> next;
        }
        while(list2) {
            ansTail->next = list2;
                ansTail = list2;
                list2 = list2 ->next;
        }
        return ansHead;
    }
};