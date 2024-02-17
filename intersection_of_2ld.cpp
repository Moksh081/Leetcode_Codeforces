#include <stack>
using namespace std;

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stackA;
        stack<ListNode*> stackB;
        
        // Push all nodes of list A into stack A
        while (headA != nullptr) {
            stackA.push(headA);
            headA = headA->next;
        }
        
        // Push all nodes of list B into stack B
        while (headB != nullptr) {
            stackB.push(headB);
            headB = headB->next;
        }
        
        ListNode* intersection = nullptr;
        
        // Pop nodes from the stacks until they are equal
        while (!stackA.empty() && !stackB.empty() && stackA.top() == stackB.top()) {
            intersection = stackA.top();
            stackA.pop();
            stackB.pop();
        }
        
        return intersection;
    }
};

