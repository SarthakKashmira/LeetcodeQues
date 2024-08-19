class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxans=nums[0];
        int n=nums.size();
        for (int i=1;i<n;i++)
        {
            if(nums[i-1]>0){
                nums[i]+=nums[i-1];
            }
            maxans=max(maxans,nums[i]);
        }
        return maxans;
    }
};