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

    void solve(TreeNode* root,unordered_set<int> &mp,bool flag,vector<TreeNode*> &ans)
    {
        if(root==NULL) return ;

        if(mp.find(root->val)!=mp.end())
        {
            solve(root->left,mp,true,ans);
            solve(root->right,mp,true,ans);
        }
        else{
            if(flag) ans.push_back(root);
            TreeNode* leftNode=root->left;
            TreeNode* rightNode=root->right;
            if(root->left)
            {
                if(mp.find(root->left->val)!=mp.end())
                {
                    root->left=NULL;
                }
            }
            if(root->right)
            {
                if(mp.find(root->right->val)!=mp.end())
                {
                 root->right=NULL;   
                }
            }
            solve(leftNode,mp,false,ans);
            solve(rightNode,mp,false,ans);
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> s(to_delete.begin(),to_delete.end());
        solve(root,s,true,ans);
        return ans;
    }
};