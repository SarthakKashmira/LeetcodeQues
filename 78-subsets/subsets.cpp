class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &temp,int ind,int n)
{
    if(ind==n)
    {
        ans.push_back(temp);
        return ;
    }
    temp.push_back(nums[ind]);
    solve(nums,ans,temp,ind+1,n);
    temp.pop_back();
    solve(nums,ans,temp,ind+1,n);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,temp,0,nums.size());
        return ans;
    }
};