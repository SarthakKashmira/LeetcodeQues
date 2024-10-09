class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxans=INT_MIN;
       int ans=0;
       for(int i=0;i<nums.size();i++)
       {
        ans+=nums[i];
        maxans=max(ans,maxans);
        if(ans<0){ans=0;}
       }
       return maxans;
    }
};