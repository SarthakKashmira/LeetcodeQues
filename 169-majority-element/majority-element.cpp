class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                ele=nums[i];
                cnt+=1;
            }
            else if(ele==nums[i])
            {
                cnt++;
            }
            else if(ele!=nums[i])
            {
                cnt--;
            }
        }
        return ele;
    }
};