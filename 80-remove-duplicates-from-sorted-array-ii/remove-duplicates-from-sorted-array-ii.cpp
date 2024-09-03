class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int slow=1;
        int fast=1;
        int count=1;
        while(fast < nums.size())
        {
            if(nums[fast]==nums[fast-1])
            {
                if(count<2)
                {
                 count++;
                }
                else{
                    nums[fast-1]=INT_MIN;
                }
            }
            else{
                count=1;
            }
            fast++;
        }
        slow=0;
        fast=1;
        while(fast<nums.size())
        {
            if(nums[fast]!=INT_MIN)
            {
                while(nums[slow]!=INT_MIN && slow<fast)
                {
                    slow++;
                }
                swap(nums[slow],nums[fast]);
            }
            fast++;
        }
        return slow+1;
    }
};