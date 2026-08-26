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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left != nullptr) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right != nullptr) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        map<TreeNode*, int> vis;
        q.push(target);
        vis[target] = 1;
        for(int i=0;i<k;i++) {
            int sz = q.size();
            for(int j=0;j<sz;j++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr && !vis.count(node->left)) {
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right != nullptr && !vis.count(node->right)) {
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(node != root && !vis.count(parent[node])) {
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> nodes;
        while(!q.empty()) {
            nodes.push_back(q.front()->val);
            q.pop();
        }

        return nodes;
    }
};