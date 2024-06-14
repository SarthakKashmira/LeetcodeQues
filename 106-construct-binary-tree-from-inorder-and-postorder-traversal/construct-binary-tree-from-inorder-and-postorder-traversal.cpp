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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int> &mp,int sp,int ep,int si,int ei,TreeNode* root)
    {
        if(sp>ep || si>ei) return NULL;
        int val=postorder[ep];
        root=new TreeNode(val);
        int ind=mp[val];
        int diff=ei-ind;
        root->right=solve(inorder,postorder,mp,ep-diff,ep-1,ind+1,ei,root->right);
        root->left=solve(inorder,postorder,mp,sp,ep-diff-1,si,ind-1,root->left);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        TreeNode* temp=NULL;
        for(int i=0;i<inorder.size();i++)
        {
            mp.insert({inorder[i],i});
        }
        return solve(inorder,postorder,mp,0,postorder.size()-1,0,inorder.size()-1,temp);
    }
};