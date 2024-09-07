class Solution {
public:
    void bfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>& board,vector<int> drow,vector<int> dcol,int n,int m)
    {
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=p.first+drow[i];
                int ncol=p.second+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O')
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> drow={0,-1,0,1};
        vector<int> dcol={-1,0,1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1 ) && board[i][j]=='O' && visited[i][j]==0)
                {
                    bfs(i,j,visited,board,drow,dcol,n,m);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};