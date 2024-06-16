class Solution {
public:
    typedef pair<float,int> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> pq;
        for(int i=0;i<points.size();i++)
        {
            float dist=sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            pq.push({dist,i});
            if(pq.size()>k){
                pq.pop();
            }
        }   
        vector<vector<int>> ans;
        while(pq.size()>0)
        {
            int i=pq.top().second;
            ans.push_back(points[i]);
            pq.pop();
        }
        return ans;
    }
};