class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // vector<int> adj[n+1];
        // vector<int> adj1[n+1];
        // int ans=-1;
        // for(auto i: trust)
        // {
        //     adj[i[0]].push_back(i[1]);
        //     adj1[i[1]].push_back(i[0]);
        // }
        // for(int i=1;i<n+1;i++)
        // {
        //     if(adj[i].size()==0 && adj1[i].size()==n-1)
        //     {
        //         ans=i;
        //     } 
        // }
        // return ans;
        vector<vector<int>> v(n+1,vector<int>(2,0));
        for(auto i: trust)
        {
            v[i[1]][0]++;
            v[i[0]][1]++;
        }
        for(int i=1;i<n+1;i++)
        {
            if(v[i][0]==n-1 && v[i][1]==0)
            {return i;}
        }
        return -1;

        
    }
};