class Solution {
public:
class disjoin{
    public:
    vector<int> rank;
    vector<int> parent;
    disjoin(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<(n+1);i++)
        {
            parent[i]=i;
        }
    }
    int findUP(int u)
    {
        if(parent[u]==u)
        {return u;}
        return parent[u]=findUP(parent[u]);
    }
    void unionRank(int u,int v)
    {
        int upu=findUP(u);
        int upv=findUP(v);
        if(rank[upu]>rank[upv])
        {
            parent[upv]=upu;
        }
        else if(rank[upv]>rank[upu])
        {
            parent[upu]=upv;
        }
        else {
            parent[upv]=upu;
            rank[upu]++;
        }
    }
};
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size()==1) return 0;
        int ans=0;
        int maxicol=0;
        int maxirow=0;
        for(auto i:stones)
        {
            maxirow=max(maxirow,i[0]);
            maxicol=max(maxicol,i[1]);
        }
        unordered_map<int,int> stoneNodes;
        disjoin ds(maxirow+maxicol+1);
        for(auto i:stones)
        {
            int noderow=i[0];
            int nodecol=i[1]+maxirow+1;
            ds.unionRank(noderow,nodecol);
            stoneNodes[noderow]=1;
            stoneNodes[nodecol]=1;
        }
        for(auto i:stoneNodes)
        {
            if(ds.findUP(i.first)==i.first)
            {
                ans++;
            }
        }
        return stones.size()-ans;
    }
};