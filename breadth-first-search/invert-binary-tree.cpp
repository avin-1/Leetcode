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
    TreeNode* invertTree(TreeNode* root) {
        // start 2 ptr at root
        // ptr1 goes left then right, ptr2 goes right then left
        // swap ptr1 an ptr2 at every iteration
        // recurse(root);
        // return root;

        if (!root) return root;
        swap(root->left, root->right);
        if (root->left) {
            invertTree(root->left);
        }
        if (root->right) {
            invertTree(root->right);
        }
        return root;
    }

    void recurse(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);
        if (root->left) {
            recurse(root->left);
        }
        if (root->right) {
            recurse(root->right);
        }
    }
};