/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, map<TreeNode*, TreeNode*>&parent) {
        if(root==nullptr) return;
        if(root->left != nullptr) parent[root->left] = root;
        if(root->right != nullptr) parent[root->right] = root;
        dfs(root->left, parent);
        dfs(root->right, parent);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> parent;
        dfs(root, parent);

        map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = 1;
        for(int i=0;i<k;i++) {
            int sz = q.size();
            for(int j=0;j<sz;j++) {
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

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};