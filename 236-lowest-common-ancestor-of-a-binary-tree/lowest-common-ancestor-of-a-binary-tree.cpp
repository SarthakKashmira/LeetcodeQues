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
    bool path(TreeNode* root,TreeNode* target,vector<TreeNode*> &path1)
    {
        if(root==NULL) return false;
        path1.push_back(root);
        if(root->val==target->val) {return true;}
        bool left=path(root->left,target,path1);
        bool right=path(root->right,target,path1);
        if(left || right){return true;}
        else{
            path1.pop_back();
            return false;
        }
        return true;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        path(root,p,path1);
        path(root,q,path2);
        int i=0;int j=0;
        TreeNode* temp=NULL;
        while(i<=(path1.size()-1) && j<=(path2.size()-1))
        {
            if(path1[i]->val==path2[j]->val){temp=path1[i];}
            i++;j++;
        }
        return temp;
    }
};