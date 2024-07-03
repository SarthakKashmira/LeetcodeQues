class Solution {
public:
// int solve(vector<int>& cardPoints, int k,int i,int j)
// {
//     if(k==0 || i>=cardPoints.size() || j<0) return 0;
//     return max((cardPoints[i]+solve(cardPoints,k-1,i+1,j)),(cardPoints[j]+solve(cardPoints,k-1,i,j-1)));
// }
    int maxScore(vector<int>& cardPoints, int k) {
        // int sum=0;
        // return solve(cardPoints,k,0,cardPoints.size()-1);
        int n=cardPoints.size();
        int maxi=0;
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++)
        {
            lsum=lsum+cardPoints[i];
        }
        maxi=lsum;
        if(n==k) return maxi;
        int q=k-1;
        for(int i=n-1;i>=n-k;i--)
        {
            lsum=lsum-cardPoints[q];
            rsum=rsum+cardPoints[i];
            maxi=max(maxi,lsum+rsum);
            q--;
        }
        return maxi;

    }
};