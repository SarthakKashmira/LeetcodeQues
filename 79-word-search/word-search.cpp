class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,vector<vector<int>> &vis,int indi,int indj,int siz,int count,int row,int col,int strind,vector<int> &drow,vector<int> &dcol)
    {
        if(count==siz)
        {
            return true;
        }
        if(indi<0 || indi>=row || indj<0 || indj>=col || vis[indi][indj])
        {return false;}
        if(board[indi][indj]==word[strind])
        {
            vis[indi][indj]=1;
            count++;
            strind++;
            for(int i=0;i<4;i++)
            {
                if(solve(board,word,vis,indi+drow[i],indj+dcol[i],siz,count,row,col,strind,drow,dcol) ) return true;
            }
            vis[indi][indj]=0;
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
         int strind=0; int count=0;
        vector<int> drow={0,-1,0,1};
        vector<int> dcol={-1,0,1,0};
        int siz=word.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(solve(board,word,vis,i,j,siz,count,n,m,strind,drow,dcol))
                {return true;}
            }
        }
        return false;
    }
};