class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int l=0;
       int r=0;
       int ans=0;
       int maxans=INT_MIN;
       while(r<nums.size())
       {
        ans+=nums[r];
        maxans=max(ans,maxans);
        if(ans<0)
        {ans=0;
        l++;}
        r++;
       }
       return maxans;
    }
};