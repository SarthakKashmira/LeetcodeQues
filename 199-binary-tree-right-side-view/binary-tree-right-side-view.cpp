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
    void solve(TreeNode* root,vector<int> &res,set<int> &mp,int curr)
    {
        if(root==NULL)
        {return ;}
        if(mp.find(curr)==mp.end())
        {
            res.push_back(root->val);
            mp.insert(curr);
        }
        solve(root->right,res,mp,curr+1);
        solve(root->left,res,mp,curr+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        set<int> mp;
        solve(root,res,mp,0);
        return res;
    }
};