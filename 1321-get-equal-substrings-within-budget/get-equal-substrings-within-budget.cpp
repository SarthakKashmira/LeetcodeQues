class Solution {
public:

    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int ans=0,window=0,left=0;
        for(int right=0;right<n;right++)
        {
            window+=abs((int)s[right]-(int)t[right]);
            while(window>maxCost){
                window-=abs((int)s[left]-(int)t[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};