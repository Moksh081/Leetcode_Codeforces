/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;  // An empty tree is symmetric
        }

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if (leftSubtree == nullptr && rightSubtree == nullptr) {
            return true;  // Both subtrees are empty, they are symmetric
        }

        if (leftSubtree == nullptr || rightSubtree == nullptr) {
            return false;  // One subtree is empty, they are not symmetric
        }

        return (leftSubtree->val == rightSubtree->val) &&
               isMirror(leftSubtree->left, rightSubtree->right) &&
               isMirror(leftSubtree->right, rightSubtree->left);
    }
};

