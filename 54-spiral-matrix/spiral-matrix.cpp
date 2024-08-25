class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(); int m=matrix[0].size();
        int rowstart=0;
        int rowend=n-1;
        int colstart=0;
        int colend=m-1;
        int i=0;int j=0;
        int count=1;
        vector<int> ans;
        while(rowstart<=rowend && colstart<=colend)
        {
            if(j==colstart && count==1)
            {
                for(;j<=colend;j++)
                {
                    cout<<matrix[i][j];
                    ans.push_back(matrix[i][j]);
                }
                j--;
                rowstart++;
                i=rowstart;
                count++;
            }
            else if(i==rowstart && count==2)
            {
                for(;i<=rowend;i++)
                {
                    cout<<matrix[i][j];
                    ans.push_back(matrix[i][j]);
                }
                i--;
                colend--;
                j=colend;
                count++;
            }
            else if(j==colend && count==3)
            {
                for(;j>=colstart;j--)
                {
                    cout<<matrix[i][j];
                    ans.push_back(matrix[i][j]); 
                }
                j++;
                rowend--;
                i=rowend;
                count++;
            }
            else {
                for(;i>=rowstart;i--)
                {
                    cout<<matrix[i][j];
                    ans.push_back(matrix[i][j]);
                }
                i++;
                colstart++;
                j=colstart;
                count=1;
            }
        }
        return ans;
    }
};