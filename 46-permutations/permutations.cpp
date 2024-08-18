class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>& nums,vector<int> &visited,vector<int> &temp)
    {
        if(nums.size()==temp.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                temp.push_back(nums[i]);
                solve(ans,nums,visited,temp);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,0);
        vector<int> temp;
        vector<vector<int>> ans;
        solve(ans,nums,visited,temp);
        return ans;
    }
};