class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        // First, find the total length of the list
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Calculate the position from the start (1-based index)
        int pos = count - n;

        // If pos is 0, it means we need to remove the head node
        if (pos == 0) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return head;
        }

        // Traverse to the node just before the one we want to delete
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        // Remove the nth node from the end
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};

