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
    vector<int> rightSideView(TreeNode* root) {
       vector<int> result;
       if(!root) return result;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        int size = q.size();
        TreeNode* loc = q.back();
        result.push_back(loc->val);
        for (int i = 0;i<size;i++){
            TreeNode* l = q.front();
            q.pop();
            if(l->left) q.push(l->left); 
            if(l->right) q.push(l->right); 
        }
       }
       return result;
    }
};