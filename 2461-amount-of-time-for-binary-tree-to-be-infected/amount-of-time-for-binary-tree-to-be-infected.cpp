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
    void dfs(TreeNode* root, int st, TreeNode* &start, map<TreeNode*, TreeNode*>&parent) {
        if(root == nullptr) return;
        if(root->val == st) start = root;
        if(root->left == nullptr && root->right == nullptr) return;
        if(root->left != nullptr) parent[root->left] = root;
        if(root->right != nullptr) parent[root->right] = root;
        dfs(root->left, st, start, parent);
        dfs(root->right, st, start, parent);
    }

    int amountOfTime(TreeNode* root, int st) {
        map<TreeNode*, TreeNode*> parent;
        TreeNode* start;
        dfs(root, st, start, parent);
        map<TreeNode*, int> vis;
        int time = -1;
        queue<TreeNode*> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()) {
            int sz = q.size();
            time++;
            for(int i=0;i<sz;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(parent[node] != nullptr && !vis.count(parent[node])) {
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                }
                if(node->left != nullptr && !vis.count(node->left)) {
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right != nullptr && !vis.count(node->right)) {
                    vis[node->right] = 1;
                    q.push(node->right);
                }
            }
        }

        return time;
    }
};