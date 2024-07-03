class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0;
        int maxi=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {len++;}
            else if(nums[i]==0 && k>0)
            { k--;  len++; }
            else if(nums[i]==0)
            {
                while(nums[j]!=0)
                { j++; }
                j++;
                len=i-j+1;
            }
            maxi=max(maxi,len);
        }
        return maxi;
    }
};