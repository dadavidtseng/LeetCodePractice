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
    static string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N";
        }

        string result;
        serialize(root, result);

        return result;
    }

    static string serialize(TreeNode const* node, string& result) {
        if (node == nullptr) {
            result.append("N");
            result.append(",");
            return result;
        }

        result.append(to_string(node->val));
        result.append(",");

        serialize(node->left, result);
        serialize(node->right, result);

        return result;
    }

    // Decodes your encoded data to tree.
    static TreeNode* deserialize(string data) {
        if (data == "N") {
            return nullptr;
        }

        TreeNode* result = nullptr;

        stringstream ss(data);
        string temp;
        char constexpr delim = ',';
        vector<string> tokens;
        int currentIdx = 0;

        while (getline(ss, temp, delim)) {
            tokens.push_back(temp);
        }

        return deserialize(tokens, currentIdx);
    }

    static TreeNode* deserialize(vector<string>& tokens, int& index) {
        TreeNode* result = nullptr;

        if (tokens[index] == "N") {
            index++;
        } else {
            result = new TreeNode(stoi(tokens[index]));
            index++;
            result->left = deserialize(tokens, index);
            result->right = deserialize(tokens, index);
        }

        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));