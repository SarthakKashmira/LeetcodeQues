class Solution {
public:

int solve(int i,int n,vector<int> &dp)
{
    if(i>n) return 0;
    if(i==n) return 1;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=(solve(i+1,n,dp)+solve(i+2,n,dp));
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};