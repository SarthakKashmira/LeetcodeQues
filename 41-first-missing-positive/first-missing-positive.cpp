class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto i:nums)
        {
            if(i>0)
            {seen.insert(i);}
        }
        int j=1;
        while(true)
        {
            if(seen.find(j)==seen.end())
            {
                return j;
            }
            else{
                j++;
            }
        }
        return -1;
    }
};