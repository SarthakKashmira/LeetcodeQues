class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<int> v=intervals[0];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=v[1])
            {
                v[1]=max(v[1],intervals[i][1]);
            }
            else if(intervals[i][0]>v[1]){
                ans.push_back(v);
                v=intervals[i];
            }
        }
        ans.push_back(v);
        return ans;
    }
};