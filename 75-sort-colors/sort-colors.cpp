class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int m=0;
        int e=n-1;
        while(m<=e)
        {
            if(nums[m]==2)
            {swap(nums[m],nums[e]);
             e--;}
            else if(nums[m]==0)
            {
                swap(nums[m],nums[l]);
                l++;
                m++;
            }
            else{
                m++;
            }
        }
        return ;
    }
};