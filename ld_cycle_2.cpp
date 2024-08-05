/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        int count = 0;

        // Detect if there's a cycle using Floyd's Cycle Detection Algorithm
        while (p != nullptr && p->next != nullptr) {
            p = p->next->next;
            q = q->next;

            if (p == q) {  // Cycle detected
                ListNode *t = head;
                // Find the start of the cycle
                while (t != q) {
                    t = t->next;
                    q = q->next;
                    count++;
                }
                cout << "Count of nodes before cycle starts: " << count << endl;
                return t;  // Return the start of the cycle
            }
        }

        return nullptr;  // No cycle found
    }
};

