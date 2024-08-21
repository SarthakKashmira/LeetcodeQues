class Solution {
public:
int solve(int &ans,int m,int n,int i,int j,vector<vector<int>> &dp)
{
    if(i>=m || j>=n)
    {return 0;}
    if(i==m-1 && j==n-1)
    { return 1; }
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=solve(ans,m,n,i+1,j,dp)+ solve(ans,m,n,i,j+1,dp);
}
    int uniquePaths(int m, int n) {
        int ans=0; int i=0; int j=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(ans,m,n,i,j,dp);
    }
};