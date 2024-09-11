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
class Solution {
public:
    // Function to calculate GCD of two numbers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to insert GCDs between adjacent nodes in the linked list
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        
        // Traverse through the list until we reach the last node
        while (current != nullptr && current->next != nullptr) {
            int gcdVal = gcd(current->val, current->next->val);  // Compute GCD
            
            // Create a new node with the GCD value
            ListNode* newNode = new ListNode(gcdVal);
            
            // Insert the new node between current and current->next
            newNode->next = current->next;
            current->next = newNode;
            
            // Move to the next original node (skipping the inserted one)
            current = newNode->next;
        }
        
        return head;
    }
};

