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
    bool check(TreeNode* r1,TreeNode* r2){
        if(r1==NULL&&r2==NULL) return true;
        if(r1==NULL||r2==NULL) return false;
        if(r1->val!=r2->val) return false;
        //if they are same then 
        else{
            bool ans = check(r1->left,r2->right);
            bool ans2 = check(r1->right,r2->left);
            if(ans == false || ans2 == false){
                return false;
            }
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        // check if root->right == root->left then it is symmetric if not then asymmetric
        return check(root->left,root->right);
    }
};