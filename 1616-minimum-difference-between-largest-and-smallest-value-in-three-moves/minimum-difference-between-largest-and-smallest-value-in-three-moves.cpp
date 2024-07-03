class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int j=n-1-3;
        for(int i=0;i<=3;i++)
        {
            int ans=nums[j]-nums[i];
            mini=min(mini,ans);
            j++;
        }
        return mini;

    }
};