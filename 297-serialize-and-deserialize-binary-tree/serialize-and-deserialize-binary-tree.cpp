/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string ser;
        queue<TreeNode*> q;
        q.push(root);
        ser += to_string(root->val);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) {
                    ser += ',';
                    ser += to_string(node->left->val);
                    q.push(node->left);
                }
                else ser += ",#";
                if(node->right != nullptr) {
                    ser += ',';
                    ser += to_string(node->right->val);
                    q.push(node->right);
                }
                else ser += ",#";
            }
        }

        cout<<ser<<'\n';
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<int> vec;
        int idx = 0;
        while(idx < data.size()) {
            if(data[idx] == '#') {
                vec.push_back(1e6);
                idx+=2;
                continue;
            }
            string no;
            while(idx < data.size() && data[idx] != ',') {
                no += data[idx];
                idx++;
            }
            idx++;
            vec.push_back(stoi(no));
        }

        TreeNode* root = new TreeNode(vec[0]);
        queue<TreeNode*> q;
        q.push(root);
        idx = 1;
        while(!q.empty() && idx < vec.size()-1) {
            TreeNode* node = q.front();
            q.pop();
            if(vec[idx] != 1e6) {
                node->left = new TreeNode(vec[idx]);
                q.push(node->left);
            }
            if(vec[idx+1] != 1e6) {
                node->right = new TreeNode(vec[idx+1]);
                q.push(node->right);
            }
            idx+=2;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));