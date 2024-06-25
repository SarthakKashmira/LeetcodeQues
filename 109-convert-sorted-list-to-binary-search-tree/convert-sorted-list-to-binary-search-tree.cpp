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
    TreeNode* solve(TreeNode* root, vector<int> &arr,int start,int end)
    {
        if(arr.size()==0) return NULL;
        if(arr.size()==1) return new TreeNode(arr[0]);
        int mid=(start+end)/2;
        root=new TreeNode(arr[mid]);
        if(mid>start)
        {
            root->left=solve(root->left,arr,start,mid-1);
        }else{root->left=NULL;}

        if(mid<end)
        {
            root->right=solve(root->right,arr,mid+1,end);
        }else{root->right=NULL;}
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int> arr;
        ListNode* node=head;
        while(node!=NULL)
        {
            arr.push_back(node->val);
            node=node->next;
        }
        TreeNode* root=NULL;
        return solve(root,arr,0,arr.size()-1);
    }
};