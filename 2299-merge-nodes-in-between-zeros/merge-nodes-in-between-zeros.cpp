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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL) return head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        int sum=0;
        while(temp !=NULL)
        {
            if(temp->val==0 && prev==NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            else if(temp->val !=0)
            {
                sum= sum + temp->val;
                ListNode* tempo=temp;
                temp=temp->next;
                prev->next=temp;
                delete(tempo);
            }
            else if(temp->val==0 && prev!=NULL)
            {
                prev->next=new ListNode(sum);
                sum=0;
                prev=prev->next;
                prev->next=temp;
                ListNode* tempo=temp;
                temp=temp->next;
                prev->next=temp;
                delete(tempo);
            }
        }
        ListNode* tempo=head;
        head=head->next;
        delete(tempo);
        return head;
    }
};