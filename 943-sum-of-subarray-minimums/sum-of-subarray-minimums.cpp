class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> s1,s2;
        vector<int> pre(n),next(n);
        for(int i=0;i<n;i++)
        {   pre[i]=i;  next[i]=n-1-i; }
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && arr[s1.top()]>arr[i])
            {
                next[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && arr[s2.top()]>=arr[i])
            {
                pre[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        long long ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
        long long x = (long long)(next[i] + 1) * (pre[i] + 1) * arr[i];
        ans = (ans + x) % mod;
         }
    return int(ans);
    }
};