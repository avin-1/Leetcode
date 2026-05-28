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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

       while(!q.empty()){
        int n = q.size();
        vector<int> re;
        for(int i = 0;i<n;i++){
             TreeNode* temp = q.front();   // FIX: always take from front
            q.pop();                      // FIX: pop after processing

            if (leftToRight) {
                re.push_back(temp->val);  // normal order
            } else {
                re.insert(re.begin(), temp->val); // FIX: reverse order
            }

            if (temp->left) q.push(temp->left);   // FIX: null check
            if (temp->right) q.push(temp->right); // FIX: null check
        }

        result.push_back(re);
        leftToRight = !leftToRight;
       }
        return result;
    }
};