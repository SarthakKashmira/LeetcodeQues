class Solution {
public:
    void solve(string s,vector<string>& wordDict,vector<string> &ans,string temp,int ind)
    {
        if(ind==s.size())
        {
            temp.erase(temp.size()-1);
            ans.push_back(temp);
            return ;}

        for(auto j:wordDict)
        {
            if(s.substr(ind,j.size())==j && (ind+j.size())<=s.size())
            {
                solve(s,wordDict,ans,temp+j+" ",ind+j.size());
            }
        }
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp="";
        solve(s,wordDict,ans,temp,0);
        return ans;
    }
};