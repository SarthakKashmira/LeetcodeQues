class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l1=0;
        int l2=0;
        int siz1=g.size();
        int siz2=s.size();
        int count=0;
        while(l1<siz1 && l2<siz2)
        {
            if(g[l1]<=s[l2])
            {
                count++;
                l1++;
                l2++;
            }
            else{
                l2++;
            }
        }
        return count;
    }
};