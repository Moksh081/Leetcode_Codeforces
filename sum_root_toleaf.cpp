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

 /*
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int currentSum) {
        if (!root) {
            return 0;
        }
        
        // Update the current sum
        currentSum = currentSum * 10 + root->val;
        
        // If it's a leaf node, return the current sum
        if (!root->left && !root->right) {
            return currentSum;
        }
        
        // Recursively compute the sum of the root-to-leaf paths
        return dfs(root->left, currentSum) + dfs(root->right, currentSum);
    }
};
*/

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

    int sumRec(TreeNode* root, int last)
    {
        if(root->left==NULL && root->right==NULL)
            return root->val + last;
        int res = 0;
        if(root->left)
        {
            res += sumRec(root->left, (root->val+last)*10);
        }
        if(root->right)
        {
            res += sumRec(root->right, (root->val+last)*10);
        }
        return res;
    }

    int sumNumbers(TreeNode* root) {
        return sumRec(root, 0);
    }
};
