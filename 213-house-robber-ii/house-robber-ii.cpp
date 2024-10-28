class Solution {
public:
   int robLinear(vector<int>& nums, int start, int end) {
    int prev2 = 0;      // Equivalent to dp[i+2] in a normal DP approach
    int prev1 = 0;      // Equivalent to dp[i+1]
    int curr = 0;       // Maximum amount that can be robbed up to the current house

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

    // Case 1: Rob from the first house to the second-last house
    int case1 = robLinear(nums, 0, n - 2);

    // Case 2: Rob from the second house to the last house
    int case2 = robLinear(nums, 1, n - 1);

    // The result is the maximum amount we can rob from either case
    return max(case1, case2);
    }
};