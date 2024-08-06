/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int n = 1;
        while (temp->next != NULL) {
            n++;
            temp = temp->next;
        }
        if (n == 1) {
            return NULL;
        }
        int mid = n / 2 - 1;
        temp = head;
        while (mid) {
            temp = temp->next;
            mid--;
        }
        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
        deleteNode->next = NULL;
        return head;
    }
};
