class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int e=nums.size()-1;
        if(e==0) return 0;
        if(nums[e]>nums[e-1]) return e;
        
        while(l<=e)
        {
            int mid=(l+e)/2;
            cout<<mid;
            
           if((mid-1)>=0 && (mid+1)<nums.size() && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if( (mid+1)<nums.size() && nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return l;
    }
};