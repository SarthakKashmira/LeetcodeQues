class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int high=matrix.size()-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid][0]==target)
            {
                return true;
            }
            else if(matrix[mid][0]<target && mid==(matrix.size()-1))
            {
                low=mid;
                break;
            }
            else if(matrix[mid][0]<target && matrix[mid+1][0]>target)
            {
                low=mid;
                break;
            }
            else if(matrix[mid][0]>target)
            {
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        cout<<low;
        int n=low;
        low=0;
        high=matrix[n].size()-1;
        if(high==0 && matrix[n][high]==target) return true;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[n][mid]==target) return true;
            else if(matrix[n][mid]>target){
                high=mid-1;
            }
            else if(matrix[n][mid]<target)
            {
                low=mid+1;
            }
        }
        return false;
    }
};