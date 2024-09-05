/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int> &ans,int low,int end)
    {
        if(low>end)
        { return NULL; }
        if(low==end)
        { return new TreeNode(ans[low]);}
        int mid=(low+end)/2;
        TreeNode* temp=new TreeNode(ans[mid]);
        temp->left=solve(ans,low,mid-1);
        temp->right=solve(ans,mid+1,end);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ans;
        while(head!=NULL)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        int low=0;
        int end=ans.size()-1;
        return solve(ans,low,end);
    }
};