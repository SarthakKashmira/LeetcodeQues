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
    TreeNode* solve(TreeNode* root,vector<int> &nums,int start,int end)
    {
        if(nums.size()==0) return NULL;
        if(nums.size()==1){ return new TreeNode(nums[0]);}
        int mid=(start+end)/2;
        root=new TreeNode(nums[mid]);
        if(mid>start){
        root->left=solve(root->left,nums,start,mid-1);
        }else{root->left=NULL;}
        if(mid<end){
        root->right=solve(root->right,nums,mid+1,end);
        }else{root->right=NULL;}
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* temp=NULL;
        return solve(temp,nums,0,nums.size()-1);
    }
};