class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       int n=nums.size();
        stack<int> s1,s2;
        vector<int> pre(n),next(n);
        for(int i=0;i<n;i++)
        {   pre[i]=i;  next[i]=n-1-i; }
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && nums[s1.top()]>nums[i])
            {
                next[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && nums[s2.top()]>=nums[i])
            {
                pre[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }


        stack<int> S1,S2;
        vector<int> pre_g(n),next_g(n);
        for(int i=0;i<n;i++)
        {   pre_g[i]=i;  next_g[i]=n-1-i; }
        for(int i=0;i<n;i++)
        {
            while(!S1.empty() && nums[S1.top()]<nums[i])
            {
                next_g[S1.top()]=i-S1.top()-1;
                S1.pop();
            }
            S1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!S2.empty() && nums[S2.top()]<=nums[i])
            {
                pre_g[S2.top()]=S2.top()-i-1;
                S2.pop();
            }
            S2.push(i);
        }

        long long x= 0,y=0;
        for(int i = 0; i < n; i++) {
        long long X = (long long)(next[i] + 1) * (pre[i] + 1) * nums[i];
        x = (x + X);
        long long Y = (long long)(next_g[i] + 1) * (pre_g[i] + 1) * nums[i];
        y = (y + Y);
         }
         return abs(x-y);
    }
};