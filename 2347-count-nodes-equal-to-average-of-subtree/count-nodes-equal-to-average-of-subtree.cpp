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
    // {sum, nodeCnt}
    pair<int,int> dfs(TreeNode* root, int &cnt) {
        if(root == nullptr) return {-1, -1};
        if(root->left == nullptr && root->right == nullptr) {
            cnt++;
            return {root->val, 1};
        }
        int sum = 0, cc = 0;
        if(root->left != nullptr) {
            auto v = dfs(root->left, cnt);
            sum += v.first;
            cc += v.second;
        }
        if(root->right != nullptr) {
            auto v = dfs(root->right, cnt);
            sum += v.first;
            cc += v.second;
        }
        cnt += (root->val == (sum + root->val)/(cc + 1));
        return {sum + root->val, cc + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};