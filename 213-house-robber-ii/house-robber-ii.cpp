class Solution {
public:
   int robLinear(vector<int>& nums, int start, int end) {
    int prev2 = 0;      
    int prev1 = 0;     
    int curr = 0;      
    for (int i = start; i <= end; ++i) {
        curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
   }
   
   int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    int case1 = robLinear(nums, 0, n - 2);
    int case2 = robLinear(nums, 1, n - 1);
    return max(case1, case2);
    }
};