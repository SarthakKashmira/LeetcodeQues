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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL && (targetSum-root->val)==0) return true;
        if(root->left==NULL && root->right==NULL && (targetSum-root->val)!=0) return false;
        bool left=false;
        bool right=false;
        if(root->left!=NULL){
           left= hasPathSum(root->left,targetSum-(root->val));
        }
        if(root->right!=NULL){
            right= hasPathSum(root->right,targetSum-(root->val));
        }
        if(left==true || right==true) return true;
        else return false;
    }
};