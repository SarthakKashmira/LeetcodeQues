// void bfs(int src,vector<int> &visited,vector<vector<int>> &edges)
// {
//     queue<int> q;
//     q.push(src);
//     visited[src]=1;
//     while(!q.empty())
//     {
//         int node=q.front();
//         q.pop();
//         for(auto i:edges[node])
//         {
//             q.push(i);
//             visited[i]=1;
//         }
//     }
// }
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
        {
            return u;
        }
        return parent[u]=findParent(parent[u]);
    }
    void unionByRank(int u,int v)
    {
        int up_u=parent[u];
        int up_v=parent[v];
        if(up_u == up_v) return ;
        if(rank[up_u] > rank[up_v])
        {
            parent[up_v]=up_u;
        }
        else if(rank[up_u] < rank[up_v])
        {
            parent[up_u]=up_v;
        }
        else{
            parent[up_u]=up_v;
            rank[up_v]++;
        }
    }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint ds(n);
        int count=0;
        for(auto i:connections)
        {
            int u=i[0];
            int v=i[1];
            if(ds.findParent(u)==ds.findParent(v))
            {
                count++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                ans++;
            }
        }
        if(count>=(ans-1))
        {
            return ans-1;
        }
        return -1;
    }
};