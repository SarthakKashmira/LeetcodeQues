class Solution {
public:
    void solve(int i,int j,int n,int m,vector<vector<int>>& grid2,vector<vector<int>>& grid1,int &count,bool flag)
    {
        queue<pair<int,int>> q;
        if(grid1[i][j]==0)
        {flag=false;}
        q.push({i,j});
        grid2[i][j]=0;
        vector<int> drow={0,-1,0,1};
        vector<int> dcol={-1,0,1,0};
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=p.first+drow[i];
                int ncol=p.second+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid2[nrow][ncol]==1)
                {
                    if(grid1[nrow][ncol]==0)
                    {
                        flag=false;
                    }
                    q.push({nrow,ncol});
                    grid2[nrow][ncol]=0;
                    
                }
            }
        }
        if(!flag){count--;}
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    count++;
                    bool flag=true;
                    solve(i,j,n,m,grid2,grid1,count,flag);
                }
            }
        }
        return count;

    }
};