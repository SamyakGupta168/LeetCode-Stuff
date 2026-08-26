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
    using ll = long long;

    int widthOfBinaryTree(TreeNode* root) {
        ll mx = 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        while(!q.empty()) {
            ll sz = q.size();
            ll l = INT_MAX, r = INT_MIN;
            ll mn = -1;
            for(int i=0;i<sz;i++) {
                TreeNode* node = q.front().first;
                ll nn = q.front().second;
                if(i == 0) mn = nn;
                l = min(l, nn);
                r = max(r, nn);
                q.pop();
                if(node->left != nullptr) q.push({node->left, 2*(nn - mn) + 1});
                if(node->right != nullptr) q.push({node->right, 2*(nn - mn) + 2});
            }
            mx = max(mx, r - l + 1);
        }

        return (int)mx;
    }
};