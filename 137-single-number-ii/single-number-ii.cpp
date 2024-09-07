class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=31;i++)
        {
            int count=0;
            for(auto it:nums)
            {
                if(it & (1<<i))
                {count++;}
            }
            if((count%3)==1)
            {
                ans=(ans | (1<<i));
            }
        }
        return ans;
    }
};