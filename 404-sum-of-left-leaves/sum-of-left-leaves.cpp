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

    void solve(TreeNode* root,int flag,int &sum)
    {
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL && flag==0){
            sum=sum+(root->val);
            return ; 
        }
        if(root->left){
            solve(root->left,0,sum);
        }
        if(root->right){
            solve(root->right,1,sum);
        }
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        solve(root,1,sum);
        return sum;
    }
};