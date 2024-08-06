class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr; // Handle edge case: empty list

        vector<int> arr;
        ListNode* temp = head;

        // Collect all values into the vector
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the values
        sort(arr.begin(), arr.end());

        // Write the sorted values back into the linked list
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }

        // Return the head of the sorted linked list
        return head;
    }
};

