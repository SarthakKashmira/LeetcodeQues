class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> mp;
        string ans="";
        int n=formula.size();
        stack<pair<string,int>> st;
        for(int i=0;i<n;i++)
        {
            char ch=formula[i];
            if(isupper(ch))
            {
                string element="";
                element+=ch;
                int j;
                for( j=i+1;j<n;j++)
                {
                    ch=formula[j];
                    if(!islower(ch)) break;
                    element+=ch;
                }
                string sdigit="";
                int k;
                for( k=j;k<n;k++)
                {
                    ch=formula[k];
                    if(!isdigit(ch)) break;
                    sdigit+=ch;
                }
                if(sdigit=="") sdigit="1";
                int digit=stoi(sdigit);
                st.push({element,digit});
                i=k-1;
            }
            else if(formula[i]=='(')
            {st.push({"(",-1});
            }
            else if(formula[i]==')')
            {
            
                string sdigit="";
                int j;
                for(j=i+1;j<n;j++)
                {
                    ch=formula[j];
                    cout<<ch;
                    if(!isdigit(ch)) break;
                    sdigit+=ch;
                }
                if(sdigit=="") sdigit="1";
                int digit=stoi(sdigit);
                vector<pair<string,int>> temp;
                pair<string,int> opening={"(",-1};
                while(st.top()!=opening)
                {
                    pair<string,int> p=st.top();
                    st.pop();
                    temp.push_back({p.first,(p.second * digit)});
                }
                st.pop();
                while(temp.size()>0)
                {
                    st.push(temp.back());
                    temp.pop_back();
                }
                i=j-1;
            }
        }
        while(!st.empty())
        {
            pair<string,int> p=st.top();
            st.pop();
            mp[p.first]+=p.second;
        }
        for(auto i:mp)
        {
            string element=i.first;
            string digit=to_string(i.second);
            if(digit=="1") digit="";
            ans+=element+digit;
        }
        return ans;
    }
};