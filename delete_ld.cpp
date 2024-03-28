class Solution {
public: 
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* q = nullptr; // Initialize q to nullptr
        while(p){
            if(p->val == val){
                if (p == head) { // If the current node is the head
                    head = p->next;
                    delete p;
                    p = head;
                } else { // If the current node is not the head
                    q->next = p->next;
                    delete p;
                    p = q->next;
                }
            } else {
                q = p; // Update q only when the current node is not deleted
                p = p->next;
            }
        }
        return head; // Return the head of the modified list
    }
};

