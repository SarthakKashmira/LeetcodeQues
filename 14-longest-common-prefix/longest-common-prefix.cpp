class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){return strs[0];}
        int ans=1e9;
        string temp=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int k=0;
            int j=0;
            int count=0;
            while(k<temp.size() && j<strs[i].size())
            {
                if(temp[k]==strs[i][j])
                {count++;}
                else{break;}
                k++;
                j++;
            }
            if(count<ans)
            {temp=temp.substr(0,count);}
        }
        return temp;
    }
};