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
    TreeNode* findLeftMost(TreeNode* root)
    {
        while(root->left!=NULL)
        {
            root=root->left;

        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
     if(root==NULL) return NULL;
     if(root->val < key){
        root->right=deleteNode(root->right,key);
     }   
     else if(root->val > key){
        root->left=deleteNode(root->left,key);
     }
     else{
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
            return root;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            root=root->right;
            return root;
        }
        if(root->left!=NULL && root->right==NULL)
        {
            root=root->left;
            return root;
        }
        else{
            TreeNode* temp=findLeftMost(root->right);
            int tempval=root->val;
            root->val=temp->val;
            temp->val=tempval;
            root->right=deleteNode(root->right,key);
        
        }

     }
     return root;
    }
};