class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        stack<int> st;
        vector<int> ids;
        for(int i=0;i<n;i++)
        {ids.push_back(i);}
        auto compare=[&](int d1,int d2){
            return positions[d1]<=positions[d2];
        };
        sort(ids.begin(),ids.end(),compare);

        for(auto i:ids)
        {
            if(directions[i]=='R')
            {st.push(i);}
            else{
                while(!st.empty() && healths[i]>0)
                {
                    if(healths[i]>healths[st.top()])
                    {
                        healths[i]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    else if(healths[i]<healths[st.top()])
                    {
                        healths[st.top()]--;
                        healths[i]=0;
                    }
                    else{
                        healths[i]=0;
                        healths[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(healths[i]>0)
            {ans.push_back(healths[i]);}
        }
        return ans;

    }
};