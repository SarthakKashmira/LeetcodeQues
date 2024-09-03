class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int end=nums.size()-1;
        while(low<=end)
        {
            int mid=(low+end)/2;
            if(nums[mid]==target)
            {return true;}
            else if(nums[low]==nums[mid] && nums[mid]==nums[end])
            {
                low++;
                end--;
            }
            else if(nums[mid]>=nums[low])
            {
                if(nums[low]<=target && target<nums[mid])
                {
                    end=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<target && target<=nums[end])
                {
                    low=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};