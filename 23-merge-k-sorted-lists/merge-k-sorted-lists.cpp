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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        for(auto i:lists)
        {
            if(i!=NULL)
            pq.push({i->val,i});
        }
        while(!pq.empty())
        {
            pair<int,ListNode*> p=pq.top();
            pq.pop();
            curr->next=p.second;
            curr=curr->next;
            if(p.second->next!=NULL)
            {
                pq.push({p.second->next->val,p.second->next});
            }
        }
        return dummy->next;

    }
};