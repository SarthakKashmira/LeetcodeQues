class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i=3;i<=numRows;i++)
        {
            vector<int> temp(i,-1);
            for(int j=0;j<i;j++)
            {
                if(j==0) {temp[j]=1;}
                else if(j==(i-1)){temp[j]=1;}
                else{
                    temp[j]=ans[i-2][j]+ans[i-2][j-1];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};