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
    void solve(TreeNode* root,vector<TreeNode*> &ans)
    {
        if(root==NULL) return ;
        solve(root->left,ans);
        ans.push_back(root);
        solve(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root,ans);
        TreeNode* temp=new TreeNode(-1);
        TreeNode* mov=temp;
        for(auto i:ans)
        {
            i->left=i->right=NULL;
            mov->right=i;
            mov=mov->right;
        }
        return temp->right;
    }
};