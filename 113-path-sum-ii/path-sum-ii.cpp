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
    void path(TreeNode* root, int targetSum,vector<vector<int>> &ans,vector<int> temp)
    {
        if(root==NULL) return ;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL && (targetSum-root->val)==0) 
        {ans.push_back(temp);
        return ;}
        bool left=false;
        bool right=false;
        
        if(root->left!=NULL){
          path(root->left,targetSum-(root->val),ans,temp);
        }
        if(root->right!=NULL){
          path(root->right,targetSum-(root->val),ans,temp);
        }
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        path(root,targetSum,ans,temp);
        return ans;
    }
};