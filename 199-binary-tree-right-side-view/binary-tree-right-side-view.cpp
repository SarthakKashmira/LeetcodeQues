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
    void solve(TreeNode* root,vector<int> &ans,set<int> &s,int level)
    {
        if(root==NULL) return ;
        if(s.find(level)==s.end())
        {
            ans.push_back(root->val);
            s.insert(level);
        }
        solve(root->right,ans,s,level+1);
        solve(root->left,ans,s,level+1);
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        set<int> s;
        solve(root,ans,s,0);
        return ans;
    }
};