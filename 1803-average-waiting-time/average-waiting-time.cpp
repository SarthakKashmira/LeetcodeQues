class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double ans=0;
        double time=0;
        for(int i=0;i<n;i++)
        {
            if(time==0)
            {
                time=customers[i][0]+customers[i][1];
                ans=ans+customers[i][1];
            }
            else if(time>customers[i][0])
            {
                ans=ans+time-customers[i][0]+customers[i][1];
                time=time+customers[i][1];
            }
            else{
                time=customers[i][0]+customers[i][1];
                ans+=customers[i][1];
            }
        }
        return ans/n;

    }
};