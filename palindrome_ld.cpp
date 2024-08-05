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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* p = head;
        ListNode* q = NULL;
        while(head!=NULL && head->next!=NULL){
            int a = head->val;
            arr.push_back(a);
            head = head->next;
        }
        while(p!=NULL){
            ListNode* t = p->next;
            p->next = q;
            q = p;
            p = t;
        }
        vector<int> ar;
        while(head!=NULL && head->next!=NULL){
            int a = head->val;
            ar.push_back(a);
            head = head->next;
        }
        if(arr == ar){
            return true;
        }
        return false;
    }
};
