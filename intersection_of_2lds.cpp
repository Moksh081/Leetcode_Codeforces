class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> A, B;
        ListNode *ptr1=headA, *ptr2=headB, *lastRead=NULL;
        while(ptr1) {
            A.push(ptr1);
            ptr1=ptr1->next;
        }
        while(ptr2) {
            B.push(ptr2);
            ptr2=ptr2->next;
        }
        while(!A.empty() && !B.empty() && (A.top()==B.top())) {
            lastRead=A.top();
            A.pop();
            B.pop();

        }
        return lastRead;
    }
};
