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
    void solve(TreeNode* root,int tempans,int &ans)
    {
        tempans=(tempans*10)+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            ans=ans+tempans;
            return ;
        }
        
        if(root->left!=NULL)
        {
           solve(root->left,tempans,ans);
        }
        if(root->right!=NULL)
        {
            solve(root->right,tempans,ans);
        }
        return ;

    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        int tempans=0;
        solve(root,tempans,ans);
        return ans;
    }
};