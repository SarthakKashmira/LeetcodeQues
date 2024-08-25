class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int rowstart=0;
        int rowend=n-1;
        int colstart=0;
        int colend=n-1;
        int counter=1;
        int i=0;int j=0;
        int count=1;
        while(count<=(n*n))
        {
            if(counter==1)
            {
                for(;j<=colend;j++)
                {
                    matrix[i][j]=count;
                    count++;
                }
                j--;
                rowstart++;
                counter++;
                i=rowstart;
            }
            else if(counter==2)
            {
                for(;i<=rowend;i++)
                {
                    matrix[i][j]=count;
                    count++;
                }
                counter++;
                i--;
                colend--;
                j=colend;
            }
            else if(counter==3)
            {
                for(;j>=colstart;j--)
                {
                    matrix[i][j]=count;
                    count++;
                }
                j++;
                rowend--;
                i=rowend;
                counter++;
            }
            else{
                for(;i>=rowstart;i--)
                {
                    matrix[i][j]=count;
                    count++;
                }
                i++;
                colstart++;
                j=colstart;
                counter=1;
            }
        }
        return matrix;
    }
};