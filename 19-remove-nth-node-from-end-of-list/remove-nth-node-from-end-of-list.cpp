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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* fast=head;
     n--;
     ListNode* slow=NULL;
     while(n>0){ fast=fast->next; n--; }
     if(fast->next==NULL)
     {head=head->next;
     return head;}
     fast=fast->next->next;
     slow=head;
     while(fast!=NULL)
     {
        fast=fast->next;
        slow=slow->next;
     }slow->next=slow->next->next;
     return head;
 }
};