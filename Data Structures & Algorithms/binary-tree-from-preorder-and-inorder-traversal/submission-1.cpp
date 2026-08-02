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
    unordered_map<int, int> inorderIndex;
    int preorderIndex = 0;

    TreeNode* build(
        const vector<int>& preorder,
        int inorderLeft,
        int inorderRight
    ) {
        if (inorderLeft > inorderRight) {
            return nullptr;
        }

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int mid = inorderIndex[rootValue];

        root->left = build(
            preorder,
            inorderLeft,
            mid - 1
        );

        root->right = build(
            preorder,
            mid + 1,
            inorderRight
        );

        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderIndex.clear();
        preorderIndex = 0;

        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        return build(
            preorder,
            0,
            static_cast<int>(inorder.size()) - 1
        );
    }
};