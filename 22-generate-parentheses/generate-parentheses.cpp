class Solution {
public:
    void solve(string s,vector<string> &ans,int maxi,int ind,int cnt)
    {
        if(ind>maxi || cnt<0) return;
        if(ind==maxi && cnt==0) 
        {
            ans.push_back(s);
            return ;
        }
        solve(s+"(",ans,maxi,ind+1,cnt+1); 
        solve(s+")",ans,maxi,ind+1,cnt-1);
    }
    vector<string> generateParenthesis(int n) {
          vector<string> ans;
          solve("(",ans,2*n,1,1);
          return ans;
    }
};