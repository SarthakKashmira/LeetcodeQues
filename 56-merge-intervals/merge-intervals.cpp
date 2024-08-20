class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(ans.size()==0)
            {
                ans.push_back(intervals[i]);
                prev=0;
            }
            else{
                if(intervals[i][0]<=ans[prev][1])
                {
                    ans[prev][1]=max(intervals[i][1],ans[prev][1]);
                }
                else{
                    ans.push_back(intervals[i]);
                    prev++;
                }
            }
        }
        return ans;

    }
};