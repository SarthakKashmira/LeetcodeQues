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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,bool> parent;
        int latest=0;
        for(auto i:descriptions)
        {
            TreeNode* parentNode=NULL;
            TreeNode* childNode=NULL;
            if(mp.find(i[0])==mp.end()){parentNode=new TreeNode(i[0]);}
            else{
                parentNode=mp[i[0]];
            }

            if(mp.find(i[1])==mp.end()){childNode=new TreeNode(i[1]);}
            else{
                childNode=mp[i[1]];
            }

            if(i[2]==1){
                parentNode->left=childNode;
            }
            else{
                parentNode->right=childNode;
            }

            parent[i[1]]=true;
            mp[i[1]]=childNode;
            mp[i[0]]=parentNode;
        }
        for(auto i:mp)
        {
            if(parent.find(i.first)==parent.end())
            {return mp[i.first];}
        }
        return NULL;
    }
};