class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        while(j>=1)
        {
            if(nums[j]>nums[j-1])
            {break;}
            j--;
        }
        if(j==0){
            sort(nums.begin(),nums.end());
            return ;
        }
        else{
            for(int k=n-1;k>=j;k--)
            {
                if(nums[k]>nums[j-1])
                {
                    swap(nums[k],nums[j-1]);
                    break;
                }
            }
            cout<<nums[0];
            sort(nums.begin()+j,nums.end());
        }
        return ;
    }
};