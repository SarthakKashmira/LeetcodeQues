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
    void solve(TreeNode* root, int x, int y,vector<int> &level,vector<int> &parent,int currlevel,int paren)
    {
        if(root==NULL) return;
        if(root->val==x)
        {
            level[0]=currlevel;
            parent[0]=paren;
        }
        if(root->val==y )
        {
            level[1]=currlevel;
            parent[1]=paren;
        }
        solve(root->left,x,y,level,parent,currlevel+1,root->val);
        solve(root->right,x,y,level,parent,currlevel+1,root->val);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        vector<int>level(2,-1);
        vector<int>parent(2,-1);
        solve(root,x,y,level,parent,0,-1);
        return ((level[0]==level[1]) && (parent[0]!=parent[1]));
    }
};