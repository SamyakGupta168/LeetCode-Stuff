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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(root == nullptr) return inorder;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        }

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            inorder.push_back(node->val);
            if(node->right != nullptr) {
                temp = node->right;
                while(temp != nullptr) {
                    st.push(temp);
                    temp = temp->left;
                }
            }
        }

        return inorder;
    }
};