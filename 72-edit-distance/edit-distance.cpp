class Solution {
public:
    int solve(string word1, string word2,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0){return j+1;}
        if(j<0) {return i+1;}
        if(dp[i][j]!=-1)
        {return dp[i][j];}
        if(word1[i]==word2[j])
        {
            return dp[i][j]=solve(word1,word2,i-1,j-1,dp);
        }
        int insert=1+solve(word1,word2,i,j-1,dp);
        int dele=1+solve(word1,word2,i-1,j,dp);
        int update=1+solve(word1,word2,i-1,j-1,dp);
        return dp[i][j]=min(insert,min(dele,update));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=word1.size()-1;
        int j=word2.size()-1;
        vector<vector<int>> dp(n,vector<int>(m,-1)); 
        return solve(word1,word2,i,j,dp);
    }
};