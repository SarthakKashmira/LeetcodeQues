class Solution {
public:
    void dfs(int i,int n,vector<int> &res)
    {
        if(i>n) return ;
        res.push_back(i);
        for(int d=0;d<=9;d++)
        {
            if((i*10)+d > n)
            {break;}
            dfs((i*10)+d,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++)
        {
            if(i>n) break;
            dfs(i,n,res);
        }
        return res;
    }
};