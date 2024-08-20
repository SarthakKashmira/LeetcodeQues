class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colzero=1;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                colzero=0;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j!=0)
                    {matrix[0][j]=0;}
                }
            }
        }
        for(int i=m-1;i>=1;i--)
        {
            if(matrix[0][i]==0)
            {
                for(int j=1;j<n;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=1;j<m;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(colzero==0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};