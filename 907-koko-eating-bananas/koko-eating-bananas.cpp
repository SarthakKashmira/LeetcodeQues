class Solution {
public:
    int calculate(vector<int>& piles,int hour)
    {
        long long int totalH=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            totalH+=ceil((double)(piles[i])/(double)(hour));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(auto i:piles)
        {
            maxi=max(maxi,i);
        }
        int s=1;int e=maxi;
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            cout<<mid<<" ";
            long long int total=calculate(piles,mid);
            if(total<=h && total>0)
            {
                e=mid-1;
            }
            else if(total>h || total<0){
                s=mid+1;
            }
        }
        return s;
    }
};