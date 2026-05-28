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
    int kthSmallest(TreeNode* root, int k) {
        if (!root && k == 1)
            return root->val;
        else if (!root)
            return -1;
        vector<int> list;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* curr = root;
        while (!s.empty() || curr != NULL) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            list.push_back(curr->val);
            curr = curr->right;
        }
        return list[k - 1];
    }
};