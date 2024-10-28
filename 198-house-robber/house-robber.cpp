class Solution {
public:
    int solve(int index,vector<int> &nums,int n,vector<int> &dp)
    {
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index]=max((solve(index+2,nums,n,dp)+nums[index]),solve(index+1,nums,n,dp));
    }
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(index,nums,n,dp);
    }
};