class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string str="11";
        for(int i=3;i<=n;i++)
        {
            int j=1;
            string temp="";
            int cnt=1;
            while(j<str.size())
            {
                if(str[j]==str[j-1])
                {
                    cnt++;
                }
                else{
                    temp=temp+to_string(cnt);
                    temp=temp+str[j-1];
                    cnt=1;
                }
                j++;
            }
            temp+=to_string(cnt);
            temp=temp+str[j-1];
            str=temp;
        }
        return str;
    }
};