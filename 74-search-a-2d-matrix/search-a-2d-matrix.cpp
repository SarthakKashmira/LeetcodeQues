class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int sc=0;int ec=n-1;
        int row=0;
       
        while(sc<=ec)
         {
            int mid=sc+(ec-sc)/2;
    
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target) {row=mid; break;}
            else if(target>matrix[mid][m-1] )
            {
                sc=mid+1;
            }
            else{
                ec=mid-1;
            }
          }
        
        int sr=0;int er=m-1;
        while(sr<=er)
        {
            int mid=sr+(er-sr)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target)
            {er=mid-1;}
            else{
                sr=mid+1;
            }
        }
        return false;

    }
};