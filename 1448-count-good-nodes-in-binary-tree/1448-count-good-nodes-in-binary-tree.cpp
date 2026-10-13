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
    int dfs(TreeNode* node, int maxSoFar) {
        if (node == nullptr) {
            return 0;
        }
        int goodNodesCount = 0;
        if (node->val >= maxSoFar) {
            goodNodesCount = 1;
            maxSoFar = node->val;
        }
        goodNodesCount += dfs(node->left, maxSoFar);
        goodNodesCount += dfs(node->right, maxSoFar);
        return goodNodesCount;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};