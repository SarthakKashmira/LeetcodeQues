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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=head;
        ListNode* prev=head->next;
        ListNode* temp=NULL;
        head=head->next;
        while(curr!=NULL && curr->next!=NULL)
        {
            prev=curr->next;
            curr->next=prev->next;
            prev->next=curr;
            if(temp!=NULL)
            {temp->next=prev;}
            temp=curr;
            curr=curr->next;
        }
        return head;

    }
};