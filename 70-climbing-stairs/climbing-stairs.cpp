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
        int var1=1;
        int var2=1;
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            ans=var1+var2;
            var1=var2;
            var2=ans;
        }
        return ans;
    }
};