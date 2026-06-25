class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "";

        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                res += "#,";
                continue;
            }

            res += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<string> vals;
        string temp;

        for (char c : data) {
            if (c == ',') {
                vals.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (vals[i] != "#") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            if (i < vals.size() && vals[i] != "#") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};