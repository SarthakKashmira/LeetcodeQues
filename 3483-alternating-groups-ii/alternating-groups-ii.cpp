class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
       int n=colors.size();
       int maxlen=1;
       int ans=0;
       for(int i=1;i<=n-1+k-1;i++)
       {
        if(colors[i%n]!=colors[(i-1+n)%n])
        {
            maxlen++;
        }
        else{
            maxlen=1;
        }

        if(maxlen>=k){ans++;}
       }
       return ans;
    }
};