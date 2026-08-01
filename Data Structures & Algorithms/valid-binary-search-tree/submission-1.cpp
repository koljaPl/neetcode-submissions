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
private:
    bool isValid(TreeNode* node, long long left_bound, long long right_bound) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= left_bound || node->val >= right_bound) {
            return false;
        }

        return isValid(node->left, left_bound, node->val) && 
               isValid(node->right, node->val, right_bound);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
