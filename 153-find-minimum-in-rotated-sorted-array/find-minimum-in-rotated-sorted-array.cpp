class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;int e=n-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(nums[s]>=nums[mid] && nums[e]>=nums[mid])
            {
                s++;e--;
            }
            else if(nums[s]<=nums[mid] && nums[mid]<=nums[e])
            {return nums[s];}
            else{
                if(nums[mid]>=nums[s] && nums[mid]>nums[e])
                {
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }

        }
        int ans=min(nums[s],nums[e]);
        return ans;
    }
};