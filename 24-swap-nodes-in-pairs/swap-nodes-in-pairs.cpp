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
        ListNode* temp=head->next;
        head->next=temp->next;
        temp->next=head;
        head=temp;
        ListNode* prev=head->next;
        ListNode* tempo=head->next->next;
        while(tempo!=NULL && tempo->next!=NULL)
        {
            ListNode* tempo1=tempo->next;
            tempo->next=tempo1->next;
            tempo1->next=tempo;
            prev->next=tempo1;
            prev=tempo;
            tempo=tempo->next;
        }
        return head;
    }
};