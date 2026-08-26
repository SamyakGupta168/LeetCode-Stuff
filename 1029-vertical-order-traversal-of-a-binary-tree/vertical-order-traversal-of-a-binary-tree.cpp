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
    void dfs(TreeNode* root, int r, int c, map<int, map<int, multiset<int>>>&mp) {
        if(root == nullptr) return;
        mp[c][r].insert(root->val);
        dfs(root->left, r+1, c-1, mp);
        dfs(root->right, r+1, c+1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        map<int, map<int, multiset<int>>> mp;
        dfs(root, 0, 0, mp);

        for(auto &p : mp) {
            vector<int> list;
            for(auto &pp : p.second) {
                for(auto node : pp.second) list.push_back(node);
            }
            ans.push_back(list);
        }

        return ans;
    }
};