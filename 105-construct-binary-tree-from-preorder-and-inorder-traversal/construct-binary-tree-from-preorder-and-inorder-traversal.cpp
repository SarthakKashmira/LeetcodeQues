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
   TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int sp, int ep, int si, int ei, unordered_map<int,int> &mp)
{
    if (si > ei || sp > ep) return NULL;
    
    // Get the current root value from the preorder list
    int rootVal = preorder[sp];
    // Create the root node
    TreeNode* root = new TreeNode(rootVal);
    
    // Find the index of the root value in the inorder list
    int ind = mp[rootVal];
    
    // Number of nodes in the left subtree
    int numLeft = ind - si;
    
    // Recursively build the left and right subtrees
    root->left = solve(preorder, inorder, sp + 1, sp + numLeft, si, ind - 1, mp);
    root->right = solve(preorder, inorder, sp + numLeft + 1, ep, ind + 1, ei, mp);
    
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> mp;
        TreeNode* temp=NULL;
        for(int i=0;i<n;i++)
        {
            mp.insert({inorder[i],i});
        }
        return solve(preorder,inorder,0,n-1,0,n-1,mp);
    }
};