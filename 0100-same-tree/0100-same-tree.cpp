/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = false;

        if (p == nullptr && q == nullptr) {
            isSame = true;
            return isSame;
        }

        if (p == nullptr || q == nullptr) {
            return isSame;
        }

        if (p->val == q->val) {
            isSame = (isSameTree(p->right, q->right) &&
                      isSameTree(p->left, q->left));
        }

        return isSame;
    }
};