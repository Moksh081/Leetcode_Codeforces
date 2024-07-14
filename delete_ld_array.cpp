#include <vector>
#include <algorithm>

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
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        if (!head) return nullptr;

        // Sort the nums vector for binary search
        std::sort(nums.begin(), nums.end());

        // Create a dummy node to handle edge cases more easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != nullptr) {
            // Use binary search to check if current->val is in nums
            if (std::binary_search(nums.begin(), nums.end(), current->val)) {
                // Delete the current node
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                // Move to the next node
                prev = current;
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
    }
};

