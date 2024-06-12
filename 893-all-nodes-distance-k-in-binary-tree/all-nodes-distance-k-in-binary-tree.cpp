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

    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        if(root==NULL) return ;
        if(root->left!=NULL){
            mp.insert({root->left,root});
        }
        if(root->right!=NULL)
        {
            mp.insert({root->right,root});
        }
        parent(root->left,mp);
        parent(root->right,mp);
    }
    void solve(TreeNode* target,int k,int dist,unordered_map<TreeNode*,TreeNode*> &mp,set<int> &visited,vector<int> &ans)
    {
        if(target==NULL) return;
        if(visited.find(target->val)!=visited.end()){return ;}
        visited.insert(target->val);
        if(dist==k && target!=NULL) {ans.push_back(target->val);return ;}
        solve(target->left,k,dist+1,mp,visited,ans);
        solve(target->right,k,dist+1,mp,visited,ans);
        solve(mp[target],k,dist+1,mp,visited,ans);
        return ;


    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL) return ans;
        unordered_map<TreeNode*,TreeNode*> mp;
        set<int> visited;
        mp.insert({root,NULL});
        parent(root,mp);
        solve(target,k,0,mp,visited,ans);
        return ans;
    }
};