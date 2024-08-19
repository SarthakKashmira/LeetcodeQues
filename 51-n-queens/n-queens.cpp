class Solution {
public:
    bool isValid(vector<string> &sudoku,int i,int j,int n)
    {
        for(int col=0;col<n;col++)
        {
            if(sudoku[i][col]=='Q' && col!=j)
            {return false;}
        }
        for(int row=0;row<n;row++)
        {
            if(sudoku[row][j]=='Q' && row!=i)
            {return false;}
        }
        int row=i+1;int col=j+1;
        while(row<n && col<n && row>=0 && col>=0)
        {
            
            if(sudoku[row][col]=='Q')
            {return false;}
            row++;
            col++;
        }
        row=i-1;col=j-1;
        while(row>=0 && col>=0 && row<n && col<n)
        {
            
            if(sudoku[row][col]=='Q')
            {return false;}
            row--; col--;
        }
        row=i-1;col=j+1;
        while(row<n && col<n && row>=0 && col>=0)
        {
            if(sudoku[row][col]=='Q')
            {return false;}
            row--;col++;
        }
        row=i+1;col=j-1;
        while(row>=0 && col>=0 && row<n && col<n)
        {
            if(sudoku[row][col]=='Q')
            {return false;}
            row++;col--;
        }
        return true;
    }
    void solve(vector<string> &temp,int row,int n,vector<vector<string>> &ans)
    {
        if(row>=n)
        {ans.push_back(temp);
        return;
        }
        for(int i=0;i<n;i++)
        {
            cout<<i<<endl;
            temp[row][i]='Q';
            if(isValid(temp,row,i,n)==true)
            {
                cout<<"Hello"<<endl;
                solve(temp,row+1,n,ans);
            }
            temp[row][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++)
        {
            str+='.';
        }
        vector<string> temp(n,str);
        vector<vector<string>> ans;
        solve(temp,0,n,ans);
        return ans;
    }
};