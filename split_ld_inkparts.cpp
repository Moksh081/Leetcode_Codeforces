class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;  // This will hold the head of each part
        int n = 0;
        ListNode* temp = head;
        
        // Count the number of nodes in the linked list
        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

        temp = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Determine the size of each part
        int as = n / k;  // base size of each part
        int es = n % k;  // extra nodes to distribute

        for (int i = 0; i < k; i++) {
            int len = 0;
            curr = temp;
            
            // Each part should have 'as' nodes, and the first 'es' parts should have 1 extra node
            int partSize = as + (es > 0 ? 1 : 0);
            es--;

            while (len < partSize && temp != nullptr) {
                prev = temp;
                temp = temp->next;
                len++;
            }
            
            if (prev != nullptr) {
                prev->next = nullptr;  // Disconnect the current part from the rest
            }

            // Add the current part's head to the result
            result.push_back(curr);
        }

        // If there are fewer nodes than parts, add nulls for empty parts
        while (result.size() < k) {
            result.push_back(nullptr);
        }

        return result;
    }
};

