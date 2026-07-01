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
    int dfs(TreeNode* root, int &maxSum) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) {
            maxSum = max(maxSum, root->val);
            return root->val;
        }

        int nodeVal = root->val;
        int leftSum = dfs(root->left, maxSum);
        int rightSum = dfs(root->right, maxSum);
        int resSum = nodeVal;
        resSum += max(leftSum, 0);
        resSum += max(rightSum, 0);
        maxSum = max(maxSum, resSum);
        return nodeVal + max(max(leftSum, rightSum), 0);
    }

    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};