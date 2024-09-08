class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        int l=0;
        int e=nums.size()-1;
        while(l<=e)
        {
            int mid=(l+e)/2;
            if(nums[l]<=nums[mid] && nums[l]<mini)
            {
                mini=nums[l];
                l=mid+1;
            }
            else if(nums[mid]<mini){
                mini=nums[mid];
                e=mid-1;

            }
            else{
                l=mid+1;
            }
        }
        return mini;
    }
};