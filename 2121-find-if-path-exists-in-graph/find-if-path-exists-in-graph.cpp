class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            if(temp==destination) return true;
            if(!visited[temp])
            {
                visited[temp]=1;
                for(auto i:adj[temp])
                {
                    q.push(i);
                }
            }
        }
        return false;
    }
};