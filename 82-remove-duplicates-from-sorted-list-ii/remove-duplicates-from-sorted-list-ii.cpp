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
        if(head==NULL) return head;
        ListNode* node=head;
        ListNode* prev=NULL;
        int flag=0;
        while(node->next!=NULL)
        {
            ListNode* temp=node->next;
            if(temp->val==node->val)
            {
                if(node==head)
                {
                    ListNode* tempo=node;
                    node=node->next;
                    head=node;
                    delete(tempo);
                    flag=1;
                }
                else{
                     ListNode* tempo=node;
                    prev->next=temp;
                    node->next=NULL;
                    node=temp;
                    delete(tempo);
                    flag=1;
                }
            }
            else{
                if(flag==1 && node==head)
                {
                    ListNode* tempo=node;
                    node=node->next;
                    head=node;
                    delete(tempo);
                    flag=0;
                }
                else if(flag==1 && node!=head)
                {
                   ListNode* tempo=node;
                   node->next=NULL;
                   node=temp;
                   prev->next=temp;
                   delete(tempo);
                   flag=0;
                }
                else if(flag==0)
                {  prev=node;   node=node->next;}
            }
        }
        if(flag==1) {
            if(node==head){
                return NULL;
            }
            else{
                prev->next=NULL;
                delete(node);
            }
        }
        return head;
    }
};