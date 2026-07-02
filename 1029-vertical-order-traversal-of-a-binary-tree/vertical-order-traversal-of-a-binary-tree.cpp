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
    void dfs(TreeNode* root, int r, int c, map<int, map<pair<int,int>, int>>&mp, int &minCol, int &maxCol) {
        if(root == nullptr) return;
        mp[c][{r, root->val}]++;
        minCol = min(minCol, c);
        maxCol = max(maxCol, c);
        dfs(root->left, r+1, c-1, mp, minCol, maxCol);
        dfs(root->right, r+1, c+1, mp, minCol, maxCol);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        map<int, map<pair<int,int>, int>> mp;
        int minCol = 0, maxCol = 0;
        dfs(root, 0, 0, mp, minCol, maxCol);
        ans.resize(maxCol - minCol + 1);

        for(auto &p : mp) {
            int c = p.first;
            for(auto &q : p.second) {
                int r = q.first.first;
                int val = q.first.second;
                int cnt = q.second;
                while(cnt--) ans[abs(minCol) + c].push_back(val);
            }
        }

        return ans;
    }
};