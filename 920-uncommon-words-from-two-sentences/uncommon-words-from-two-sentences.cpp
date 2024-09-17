class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,pair<int,int>> mp;
        string temp="";
        for(auto i:s1)
        {
            
            if(i==' ')
            {
                if(mp.find(temp)==mp.end())
                {
                    mp.insert({temp,{1,0}});
                }
                else{
                    mp[temp].first++;
                }
                temp="";
            }
            else{
                temp=temp+i;
            }
        }
        if(temp.size()!=0)
        {
            if(mp.find(temp)==mp.end())
            {
                mp.insert({temp,{1,0}});
            }
            else{
                mp[temp].first++;
            }
        }
        temp="";
        for(auto i:s2)
        {
            if(i==' ')
            {
                if(mp.find(temp)==mp.end())
                {
                    mp.insert({temp,{0,1}});
                }
                else{
                    mp[temp].second++;
                }
                temp="";
            }
            else{
                temp=temp+i;
            }
        }
        if(temp.size()!=0)
        {
            if(mp.find(temp)==mp.end())
            {
                mp.insert({temp,{0,1}});
            }
            else{
                mp[temp].second++;
            }
        }
        vector<string> ans;
        for(auto i:mp)
        {
            if((i.second.first==0 && i.second.second==1) || (i.second.second==0 && i.second.first==1))
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};