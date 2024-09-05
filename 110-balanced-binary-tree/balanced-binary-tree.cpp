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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {return 0;}
        int lefty=1+height(root->left);
        int righty=1+height(root->right);
        return max(lefty,righty);
    }
    bool solve(TreeNode* root)
    {
        if(root==NULL)
        {return true;}
        int lef=height(root->left);
        int righ=height(root->right);
        if(abs(lef-righ)>1)
        {return false;}
        return (solve(root->left)&&solve(root->right));
    }
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};