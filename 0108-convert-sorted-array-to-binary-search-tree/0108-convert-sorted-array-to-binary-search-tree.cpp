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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildFromRange(nums, 0, static_cast<int>(nums.size()) - 1);
    }

private:
    static TreeNode* buildFromRange(vector<int> const& nums, int lo, int hi) {
        if (lo > hi)
            return nullptr; // empty range = no node

        int mid = lo + (hi - lo) / 2; // pick the middle of the current slice
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = buildFromRange(nums, lo, mid - 1);
        node->right = buildFromRange(nums, mid + 1, hi);

        return node;
    }
};