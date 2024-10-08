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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL )
        {
            return head;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=head;
        ListNode *temp=head->next;
        while(temp!=NULL)
        {
            if(temp->val==prev->val)
            {
                temp=temp->next;
                prev->next=temp;   
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        return dummy->next;
    }
};