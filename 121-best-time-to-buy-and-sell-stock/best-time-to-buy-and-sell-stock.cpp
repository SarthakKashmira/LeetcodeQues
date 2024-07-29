class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,0);
        int maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,prices[i]);
            dp[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]-prices[i]);
        }
        return ans;
    }
};