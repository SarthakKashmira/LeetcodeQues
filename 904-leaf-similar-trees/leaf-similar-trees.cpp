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
    
    void solve(TreeNode* root,vector<int> &v)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return ;
        }
        if(root->left) {
            solve(root->left,v);
        }
        if(root->right){
            solve(root->right,v);
        }
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        solve(root1,a);
        solve(root2,b);
        return a==b;
    }
};