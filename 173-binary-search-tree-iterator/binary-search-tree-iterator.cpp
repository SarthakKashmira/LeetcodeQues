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
class BSTIterator {
public:
    vector<int> inorder;
    int n;
    void solve(TreeNode* root)
    {
        if(root==NULL)
        return ;
        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }
    BSTIterator(TreeNode* root) {
        solve(root);
        n=-1;
    }
    
    int next() {
        if((n+1) < inorder.size())
        {
            n=n+1;
            return inorder[n];
        }
        return -1;
    }
    
    bool hasNext() {
        if((n+1) < inorder.size())
        {return true;}
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */