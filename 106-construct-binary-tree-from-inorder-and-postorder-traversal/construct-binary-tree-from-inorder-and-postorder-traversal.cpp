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
    TreeNode* solve(vector<int>& postorder,vector<int>& inorder,int ps,int pe,int is,int ie)
    {
        if(ps>pe || is>ie)
        {return NULL;}
        if(ps==pe)
        {return new TreeNode(postorder[ps]);}

        int ind=0;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==postorder[pe])
            {
                ind=i;
                break;
            }
        }
        TreeNode* temp=new TreeNode(postorder[pe]);
        temp->left=solve(postorder,inorder,ps,pe-ie+ind-1,is,ind-1);
        temp->right=solve(postorder,inorder,pe-ie+ind,pe-1,ind+1,ie);
        return temp;
        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ps=0;
        int pe=postorder.size()-1;
        int is=0;
        int ie=inorder.size()-1;
        return solve(postorder,inorder,ps,pe,is,ie);
    }
};