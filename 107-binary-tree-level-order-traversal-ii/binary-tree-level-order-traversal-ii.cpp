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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* tempo=q.front();
            q.pop();
            if(tempo==NULL)
            {
                ans.insert(ans.begin(),temp);
                temp.clear();
                if(!q.empty())
                {q.push(NULL);}
            }
            else{
                temp.push_back(tempo->val);
                if(tempo->left)
                {
                    q.push(tempo->left);
                }
                if(tempo->right)
                {
                    q.push(tempo->right);
                }

            }
        }
        return ans;
    }
};