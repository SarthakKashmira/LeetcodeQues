class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;int j=1;
        int n=nums.size();
        if(n==1) return 1;
        while(j<n)
        {
            if(nums[j]==nums[j-1])
            {nums[j-1]=101;}
            j++;
        }
        i=0;j=0;
        while(j<n)
        {
            if(nums[j]!=101)
            {
                nums[i]=nums[j]; i++;
            }
            j++;
        }
        return i;
        
    }
};