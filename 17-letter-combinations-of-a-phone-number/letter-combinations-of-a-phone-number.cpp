class Solution {
public:
    void solve(string &digits,string &temp,vector<string> &ans,unordered_map<char,string> mp,int ind)
    {
        if(ind==digits.size())
        {
            ans.push_back(temp);
            return ;
        }
        string ext=mp[digits[ind]];
        cout<<ext;
        for(auto i:ext)
        {
            temp.push_back(i);
            solve(digits,temp,ans,mp,ind+1);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {return {};}
        unordered_map<char,string> mp;
        mp.insert({'2',"abc"});
        mp.insert({'3',"def"});
        mp.insert({'4',"ghi"});
        mp.insert({'5',"jkl"});
        mp.insert({'6',"mno"});
        mp.insert({'7',"pqrs"});
        mp.insert({'8',"tuv"});
        mp.insert({'9',"wxyz"});
        string temp="";
        vector<string> ans;
        solve(digits,temp,ans,mp,0);
        return ans;
    }
};