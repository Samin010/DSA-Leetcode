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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }
    void print(int r, int c, TreeNode* root, vector<vector<string>>& ans,
               int h) {
        if (root == NULL) {
            return;
        }

        string val = to_string(root->val);
        ans[r][c] = val;
        int left_col = c - pow(2, h - r - 1);
        int right_col = c + pow(2, h - r - 1);
        print(r + 1, left_col, root->left, ans, h);
        print(r + 1, right_col, root->right, ans, h);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root) - 1;
        int r = h + 1;
        int c = pow(2, h + 1) - 1;
        vector<vector<string>> ans(r, vector<string>(c, ""));
        int start_row = 0;
        int start_col = c / 2;
        print(start_row, start_col, root, ans, h);
        return ans;
    }
};