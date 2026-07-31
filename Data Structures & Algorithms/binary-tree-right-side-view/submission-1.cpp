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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root) {
            return res;
        }


        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int levelSize = static_cast<int>(q.size());

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop_front();

                if (i == levelSize - 1) {
                    res.push_back(node->val);
                }

                if (node->left) {
                    q.push_back(node->left);
                }

                if (node->right) {
                    q.push_back(node->right);
                }
            }
        }

        return res;
    }
};