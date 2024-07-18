class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int pix=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        visited[sr][sc]=1;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            int row=p.first;
            int col=p.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==pix && !visited[nrow][ncol])
                {
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                    visited[nrow][ncol]=1;
                }
            }
        }
        return image;
    }
};