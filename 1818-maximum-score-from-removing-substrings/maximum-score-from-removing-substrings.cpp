class Solution {
public:
int solve(string &s,string s1,int x)
{
    int ans=0;int n=s.size(); int wind=0;

    for(int i=0;i<n;i++)
    {
        s[wind++]=s[i];
        if(wind>1 && s[wind-1]==s1[1] && s[wind-2]==s1[0])
        {
            wind=wind-2;
            ans=ans+x;
        }
    }
    s=s.substr(0,wind);
    return ans;
}
    int maximumGain(string s, int x, int y) {
        string s1="ab"; string s2="ba";
        if(x<y) {swap (s1,s2);swap(x,y);}
        return solve(s,s1,x)+solve(s,s2,y);
    }
};