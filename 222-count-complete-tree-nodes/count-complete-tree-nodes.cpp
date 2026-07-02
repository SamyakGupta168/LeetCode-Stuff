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
    int leftHeight(TreeNode* node) {
        int ht = 0;
        while(node != nullptr) {
            ht++;
            node = node->left;
        }
        return ht;
    }

    int rightHeight(TreeNode* node) {
        int ht = 0;
        while(node != nullptr) {
            ht++;
            node = node->right;
        }
        return ht;
    }

    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh) return (1<<lh) - 1;
        return 1 + dfs(root->left) + dfs(root->right);
    }

    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};