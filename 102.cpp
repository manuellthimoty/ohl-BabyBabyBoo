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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        vector<vector<int>> ans;

        while (!q.empty()) {
            auto [cur, depth] = q.front();
            q.pop();
            if (depth == ans.size())ans.push_back({});
            ans[depth].push_back(cur->val);
            if (cur->left) q.push({cur->left, depth + 1});
            if (cur->right) q.push({cur->right, depth + 1});
        }
        return ans;
    }
};