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
string path1;
string path2;
TreeNode* Lca(TreeNode* node,int p,int q)
{
    if(node==NULL) return node;
    TreeNode* left=Lca(node->left,p,q);
    TreeNode* right=Lca(node->right,p,q);
    if((left && right) || (node->val==p) || (node->val==q))
    {return node;}
    return left==NULL?right:left;
}
    void solve(TreeNode* root,int n,int m,string &path)
    {
        if(root==NULL) return ;
        if(root->val==n) path1=path;
        if(root->val==m) path2=path;
        path.push_back('L');
        solve(root->left,n,m,path);
        path.pop_back();
        path.push_back('R');
        solve(root->right,n,m,path);
        path.pop_back();
       
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=Lca(root,startValue,destValue);
        string path;
        solve(lca,startValue,destValue,path);
        int i=0;
        while(i<path1.size())
        {
             path1[i]='U';
             i++;
        }
        return path1+path2;
    }
};