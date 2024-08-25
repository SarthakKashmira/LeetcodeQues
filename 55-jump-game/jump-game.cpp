class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int i=0;
        while(i<=maxi)
        {
            maxi=max(maxi,i+nums[i]);
            if(maxi>=(nums.size()-1)) 
            {return true;}
            i++;
        }
        return false;
    }
};