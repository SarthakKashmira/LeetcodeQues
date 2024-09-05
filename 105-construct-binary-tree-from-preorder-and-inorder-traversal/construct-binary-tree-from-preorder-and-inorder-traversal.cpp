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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie)
    {
        if(ps>pe || is>ie)
        { return NULL; }
        if(ps==pe){ return new TreeNode(preorder[ps]); }
        int ind=0;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==preorder[ps])
            {
                ind=i;
                break;
            }
        }
        TreeNode* temp=new TreeNode(preorder[ps]);
        temp->left=solve(preorder,inorder,ps+1,ps+ind-is,is,ind-1);
        temp->right=solve(preorder,inorder,ps+ind-is+1,pe,ind+1,ie);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ps=0;
        int pe=preorder.size()-1;
        int is=0;
        int ie=inorder.size()-1;
        return solve(preorder,inorder,ps,pe,is,ie);
    }
};