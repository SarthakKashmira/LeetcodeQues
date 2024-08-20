class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        int maxans=prices[n-1];
        int ans=0;
        int j=n-1;
        while(j>=0)
        {
            maxans=max(maxans,prices[j]);
            if((maxans-prices[j])>ans)
            {
                ans=maxans-prices[j];
            }
            j--;
        }
        return ans;
    }
};