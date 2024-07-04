class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;int j=0;int ans=0;int maxf=0;
        int hash[26]={0};
        while(j<n)
        {
            hash[s[j]-'A']++;
            maxf=max(maxf,hash[s[j]-'A']);
            if((j-i+1)-maxf<=k)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else if((j-i+1)-maxf>k)
            {
                hash[s[i]-'A']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};