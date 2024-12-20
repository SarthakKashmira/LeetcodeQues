class Solution {
public:
    int solve(int m ,int n,int i,int j,int &ans,vector<vector<int>> &dp)
    {
        if(i==m-1 || j==n-1)
        {
            return 1;
        }
        if(i>=m || j>=n){return 0;}
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=(solve(m,n,i,j+1,ans,dp)+solve(m,n,i+1,j,ans,dp));
    }
    int uniquePaths(int m, int n) {
       int ans=0;
       vector<vector<int>> dp(m,vector<int>(n,-1));
       return solve(m,n,0,0,ans,dp);
    }
};