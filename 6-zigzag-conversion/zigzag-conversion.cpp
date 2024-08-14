class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){return s;}
        vector<string> v(numRows);
        int n=1;
        bool flag=true;
        for(int i=0;i<s.size();i++)
        {
            v[n-1].push_back(s[i]);
            if(n==numRows)
            {flag=false;}
            if(n==1)
            {flag=true;}
            if(flag)
            {n++;}
            else{
                n--;
            }
        }
        string res;
        for(auto i:v)
        {res+=i;}
        return res;
    }
};