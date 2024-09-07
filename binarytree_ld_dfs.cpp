class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true; // We've matched the entire linked list
        }
        if (root == nullptr) {
            return false; // Reached a null node in the tree before finishing the list
        }
        if (head->val != root->val) {
            return false; // Values don't match
        }
        // Continue to check both the left and right subtrees
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) {
            return false; // Tree is empty
        }
        // Check if the linked list starts from the current root or any of the left or right subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

