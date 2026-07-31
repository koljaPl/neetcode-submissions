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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int q_len = q.size();
            vector<int> level;

            for (int i = 0; i < q_len; i++) {
                TreeNode* node = q.front();
                q.pop_front();

                if (node) {
                    level.push_back(node->val);
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
            }

            if (!level.empty()) {
                res.push_back(level);
            }
        }

        return res;
    }
};