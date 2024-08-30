class Solution {
public:
    int solve(vector<int>& prices,int ind,int n,int pick,vector<vector<int>> &dp)
    {
        if(ind>=n)
        {
             return 0;
        }
        if(dp[ind][pick]!=-1)
        {return dp[ind][pick];}
        if(pick)
        {
            return dp[ind][pick]=max(solve(prices,ind+1,n,pick,dp),prices[ind]+solve(prices,ind+1,n,0,dp));
        }
            return dp[ind][pick]=max(solve(prices,ind+1,n,pick,dp),-prices[ind]+solve(prices,ind+1,n,1,dp));
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ind=0;
        int pick=0;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,ind,n,pick,dp);
    }
};