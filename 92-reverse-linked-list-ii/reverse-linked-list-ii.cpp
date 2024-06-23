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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return head;
        ListNode* node=head;
        ListNode* lef=NULL;
        ListNode* rig=NULL;
        ListNode* prev=NULL;
        int count=1;
        while(node!=NULL)
        {
            if(node!=NULL )
            {  if(node->next!=NULL){ if((count+1)==left) prev=node; }  }
               if(count==left){ lef=node;}
               if(count==right){ rig=node;}
               node=node->next;
               count++;  
        }
        while(lef!=rig)
        {
            ListNode* tempo=lef;
            lef=lef->next;
            tempo->next=rig->next;
            rig->next=tempo;
        }
        if(prev==NULL){head=rig;}
        else{
            prev->next=rig;
        }
        return head;
    }
};