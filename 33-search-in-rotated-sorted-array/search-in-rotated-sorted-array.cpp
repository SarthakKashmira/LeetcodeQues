class Solution {
public:
int binarysearch(vector<int>& nums, int target,int s,int e) {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0])
            {s=mid+1;}
            else{
                e=mid;
            }
        }
        
            int ans1=binarysearch(nums, target,0,s-1);
            int ans2=binarysearch(nums, target,s,nums.size()-1);

            if(ans1!=-1){return ans1;}
            else if(ans2!=-1){return ans2;}
            return -1;
    }
};