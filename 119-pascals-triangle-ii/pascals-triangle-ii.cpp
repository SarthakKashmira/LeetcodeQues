class Solution {
public:
    int nCr(int n,int r)
    {
        
        long long res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        rowIndex=rowIndex+1;
        for (int i=1;i<=rowIndex;i++)
        {
            int tempo=nCr(rowIndex-1,i-1);
            ans.push_back(tempo);
        }
        return ans;
    }
};