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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n = desc.size();
        map<int, TreeNode*> mp;
        map<int,int> isChild;
        for(int i=0;i<n;i++) {
            int parent = desc[i][0], child = desc[i][1], left = desc[i][2];
            if(!isChild.count(parent)) isChild[parent] = 0;
            isChild[child] = 1;
            TreeNode* par = NULL;
            TreeNode* ch = NULL;
            if(mp.count(parent)) par = mp[parent];
            else {
                par = new TreeNode(parent);
                mp[parent] = par;
            }

            if(mp.count(child)) ch = mp[child];
            else {
                ch = new TreeNode(child);
                mp[child] = ch;
            }

            if(left) {
                par->left = ch;
            } else {
                par->right = ch;
            }
        }

        for(auto p : isChild) {
            if(!p.second) return mp[p.first];
        }

        return NULL;
    }
};