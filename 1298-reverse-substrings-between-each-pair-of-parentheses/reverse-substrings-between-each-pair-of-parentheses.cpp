class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n=s.size();
        string sub="";
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    char c=st.top(); sub=sub+c; st.pop();
                }
                st.pop();
                if(st.empty())  { cout<<ans;ans=ans+sub; sub="";}
                else
                {  
                    for(int k=0;k<sub.size();k++)
                    {  st.push(sub[k]);}
                        sub="";
                }
            }
            else if(s[i]=='(' || st.size()!=0){
               st.push(s[i]);
            }
            else{
                ans=ans+s[i];
            }
        }
        
        // while(!st.empty())
        // {
        //     if(st.top()==')' || st.top()=='(')
        //     {
        //         st.pop();
        //     }
        //     else{
        //         char c=st.top();
        //         ans=ans+c;
        //         st.pop();
        //     }
        // }
        return ans;
    }
};