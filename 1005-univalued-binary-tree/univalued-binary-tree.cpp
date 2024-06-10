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
    void solve(TreeNode* root,int valu,bool &ans)
    {
        if(root==NULL) return ;
        solve(root->left,valu,ans);
        if(root->val!=valu){
            ans=false;
        }
        solve(root->right,valu,ans);
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int valu=root->val;
        bool ans=true;
        solve(root,valu,ans);
        return ans;
    }
};