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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        // we have to find the depth of the tree we wil follow the bfs
        // for bfs we use queue 
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            // while q is not empty we have to insert all childs of the root in tin queue and after all childs increment the answer!
            int n = q.size();
            for(int i = 0;i<n;i++){
               TreeNode* temp =  q.front();
               q.pop();
               if(temp->left!=NULL) q.push(temp->left);
               if(temp->right!=NULL)q.push(temp->right);
            }
            ans++;
        }
        return ans;
    }
};