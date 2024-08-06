class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Handle edge cases: empty list or single node

        vector<int> odd;
        vector<int> eve;
        ListNode* temp = head;
        int index = 1; // Start index from 1 (1-based indexing)

        // Traverse the linked list and separate values based on their indices
        while (temp != nullptr) {
            if (index % 2 != 0) {
                odd.push_back(temp->val); // Odd index
            } else {
                eve.push_back(temp->val); // Even index
            }
            temp = temp->next;
            index++;
        }

        temp = head; // Reset the temp pointer to the start of the list
        int i = 0;

        // Assign odd-indexed values first
        while (i < odd.size()) {
            temp->val = odd[i];
            temp = temp->next;
            i++;
        }

        i = 0;

        // Assign even-indexed values after odd-indexed values
        while (i < eve.size()) {
            temp->val = eve[i];
            temp = temp->next;
            i++;
        }

        return head;
    }
};

