class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int st=0;
        int end=n-1;
     
        while(st<=end)
          {
            int mid=(st+end)/2;
            if(matrix[mid][0]==target)
            {return true;}
            else if(matrix[mid][0]>target)
            {
                end=mid-1;
            }
            else{
                st=mid+1;
            }
          }
        int row=end;
        if(row<0) return false;
        cout<<row;
        st=0;
        end=m-1;
        while(st<=end)
        {
            int mid=(st+end)/2;
            if(matrix[row][mid]==target)
            {return true;}
            else if(matrix[row][mid]>target)
            {
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return false;
    }
};