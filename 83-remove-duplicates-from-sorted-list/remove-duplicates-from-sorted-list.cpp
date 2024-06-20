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
        while(node->next!=NULL)
        {
          ListNode* temp=node->next;
          if(temp->val==node->val)
          {node->next=temp->next;
           delete(temp); 
          }
          else{
            node=node->next;
          }
        }
        return head;
    }
};