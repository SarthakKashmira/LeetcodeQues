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
    vector<TreeNode*> solve(int low,int end)
    {
        if(low>end)
        {
            return {NULL};
        }
        if(low==end)
        {
            TreeNode* temp=new TreeNode(low);
            return {temp};
        }
        vector<TreeNode*> result;
        for(int i=low;i<=end;i++)
        {
          vector<TreeNode*> left =solve(low,i-1);
          vector<TreeNode*> right =solve(i+1,end);
          for(auto l:left)
          {
            for(auto r:right)
            {
                TreeNode* root=new TreeNode(i);
                root->left=l;
                root->right=r;
                result.push_back(root);
            }
          }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};