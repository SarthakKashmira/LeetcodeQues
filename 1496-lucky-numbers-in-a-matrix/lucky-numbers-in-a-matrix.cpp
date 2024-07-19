class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        vector<int> mini(n,INT_MAX);
        vector<int> maxi(m,INT_MIN);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mini[i]>matrix[i][j]){mini[i]=matrix[i][j];}
                if(maxi[j]<matrix[i][j]){maxi[j]=matrix[i][j];}
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mini[i]==maxi[j]){
                    ans.push_back(mini[i]);
                }
            }
        }
        return ans;
    }
};