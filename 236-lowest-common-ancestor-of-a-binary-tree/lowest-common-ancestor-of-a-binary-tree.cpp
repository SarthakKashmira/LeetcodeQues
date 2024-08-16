/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, TreeNode* p, TreeNode* q,vector<vector<TreeNode*>> &paths,vector<TreeNode*> &path)
    {
        if(root==NULL)
        {return ;}
        path.push_back(root);
        if(root==p)
        {paths[0]=path;}
        if(root==q)
        {paths[1]=path;}
        solve(root->left,p,q,paths,path);
        solve(root->right,p,q,paths,path);
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> paths(2);
        vector<TreeNode*> path;
        solve(root,p,q,paths,path);
        int i=0;int j=0;
        TreeNode* ans=NULL;
        while(i<paths[0].size() && j<paths[1].size() && paths[0][i]==paths[1][j] )
        {
            ans=paths[0][i];
            i++;
            j++;
        }
        return ans;

    }
};