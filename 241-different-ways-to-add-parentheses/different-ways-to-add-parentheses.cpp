class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]=='-' || expression[i]=='+' || expression[i]=='*')
            {
                string left=expression.substr(0,i);
                string right=expression.substr(i+1);
                vector<int> leftAns=diffWaysToCompute(left);
                vector<int> rightAns=diffWaysToCompute(right);
                for(auto j:leftAns)
                {
                    for(auto k:rightAns)
                    {
                        if(expression[i]=='-')
                        {
                            ans.push_back(j-k);
                        }else if(expression[i]=='+'){
                            ans.push_back(j+k);
                        }
                        else{
                            ans.push_back(j*k);
                        }
                    }
                }   
            }
           
        }
        if(ans.size()==0) ans.push_back(stoi(expression));
        return ans;
    }
};