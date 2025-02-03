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
    TreeNode* solve(int l, int r, vector<int>& arr) {
        if (l > r)
            return NULL;
        int pivot = 0;
        int max_val = -1;
        for (int i = l; i <= r; i++) {
            if (arr[i] > max_val) {
                max_val = arr[i];
                pivot = i;
            }
        }
        TreeNode* root = new TreeNode(max_val);
        root->left = solve(l, pivot - 1, arr);
        root->right = solve(pivot + 1, r, arr);
        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n - 1, nums);
    }
};