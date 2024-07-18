class Solution {
public:
void bfs(int i,int j,vector<vector<char>> &grid,int n,int m)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    int drow[]={0,-1,0,1};
    int dcol[]={-1,0,1,0};
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        int row=p.first;
        int col=p.second;
        q.pop();
        grid[row][col]='0';
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1')
            {
                q.push({nrow,ncol});
                grid[nrow][ncol]='0';
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,grid,row,col);
                }
            }
        }
        return count;
    }
};