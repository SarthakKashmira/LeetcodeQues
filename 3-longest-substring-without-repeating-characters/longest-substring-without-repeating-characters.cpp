class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int len=0;
        unordered_map<char,int> mp;
        int i=0;int j=0;
        while(i<s.size() && j<s.size())
        {
            if(mp.find(s[j])==mp.end())
            {mp[s[j]]=0;}
            mp[s[j]]++;
            len++;
            if(mp[s[j]]==1)
            {
            }
            else{
                while(mp[s[j]]>1 && i<j)
                {
                    mp[s[i]]--;
                    i++;
                    len--;
                }
            }
            j++;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};