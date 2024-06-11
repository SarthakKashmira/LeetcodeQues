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
    void solve(TreeNode* p,TreeNode* q,bool &ans)
    {
        if(p==NULL && q==NULL) return ;
        if(p==NULL || q==NULL || p->val!=q->val) {ans=false;return;}
        solve(p->left,q->right,ans);
        solve(p->right,q->left,ans);
        return ;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=true;
        solve(root->left,root->right,ans);
        return ans;
    }
};