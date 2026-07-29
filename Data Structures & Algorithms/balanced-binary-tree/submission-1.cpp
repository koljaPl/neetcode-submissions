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
    int height(TreeNode* node) {
        if (!node)
            return 0;
            
        int left_h = height(node->left);

        if (left_h == -1)
            return -1;
        
        int right_h = height(node->right);

        if (right_h == -1)
            return -1;
        
        if (abs(left_h - right_h) > 1) 
            return -1;
        
        return max(left_h, right_h) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};