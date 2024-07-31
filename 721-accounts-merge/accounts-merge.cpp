class Solution {
public:
    class disjoint{
        public:
        vector<int> rank,parent;
        disjoint(int v)
        {
            rank.resize(v,0);
            parent.resize(v,0);
            for(int i=0;i<v;i++)
            {
                parent[i]=i;
            }
        }
        int findParent(int u)
        {
            if(parent[u]==u)
            return u;
            return parent[u]=findParent(parent[u]);
        }
        void unionByRank(int v,int u)
        {
            int upu=findParent(u);
            int upv=findParent(v);
            if(upu==upv) return ;
            if(rank[upu]>rank[upv])
            {
                parent[upv]=upu;
            }
            else if(rank[upv]>rank[upu])
            {
                parent[upu]=upv;
            }
            else{
                parent[upu]=upv;
                rank[upv]++;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint d(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {
                    mp.insert({accounts[i][j],i});
                }
                else{
                    d.unionByRank(i,mp[accounts[i][j]]);
                }
            }
        }
        vector<string> mapping[n];
        for(auto i:mp)
        {
            int up=d.findParent(i.second);
            mapping[up].push_back(i.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mapping[i].size()==0) continue;
            else{
                sort(mapping[i].begin(),mapping[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto j:mapping[i])
                {
                    temp.push_back(j);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};