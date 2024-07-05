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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v(2);
        v[0]=INT_MAX;
        v[1]=INT_MIN;
        ListNode* temp=head;
        int prev=-1;
        int nexty=-1;
        int count=1;
        int first=-1;
        while(temp->next->next!=NULL)
        {
            if(temp->next->val > temp->next->next->val && temp->next->val > temp->val)
            {
                if(prev==-1)
                {prev=count+1;
                first=count+1;}
                else{
                    nexty=count+1;
                    v[0]=min(v[0],nexty-prev);
                    v[1]=max(v[1],nexty-prev);
                    prev=nexty;
                }
            }
            else if(temp->next->val < temp->next->next->val && temp->next->val < temp->val)
            {
                if(prev==-1)
                {prev=count+1;
                first=count+1;}
                else{
                    nexty=count+1;
                    v[0]=min(v[0],nexty-prev);
                    v[1]=max(v[1],nexty-prev);
                    prev=nexty;
                }
            }
            temp=temp->next;
            count++;
        }
        if(first!=-1 && nexty!=-1){v[1]=nexty-first;}
        if(v[0]==INT_MAX){v[0]=-1;}
        if(v[1]==INT_MIN){v[1]=-1;}

        return v;
    }
};