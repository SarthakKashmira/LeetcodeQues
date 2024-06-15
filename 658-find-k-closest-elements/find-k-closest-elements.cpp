class Solution {
public:
typedef pair<int,pair<int,int>> ppi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<ppi> pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),{i,arr[i]}});
            if(pq.size()>k)
            {pq.pop();}
        }
        vector<int> ans;
        while(pq.size()>0)
        {
            ans.push_back(pq.top().second.second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};