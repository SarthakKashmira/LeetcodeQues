class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        vector<int> ans(2,-1);
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                int l=mid;
                int r=mid;
                while( l>-1 && nums[l]==target )
                {l--;}
                ans[0]=l+1;
                while( r<nums.size() && nums[r]==target )
                {r++;}
                ans[1]=r-1;
                return ans;
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
                
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};