class Solution {
public:
    bool checkValidString(string s) {
            int mini=0;
            int maxi=0;
            for(auto i:s)
            {
                if(i=='(')
                {
                    mini+=1;
                    maxi+=1;
                }
                else if(i==')')
                {
                    mini-=1;
                    maxi-=1;
                }
                else{
                    mini-=1;
                    maxi+=1;
                }
                if(mini<0) mini=0;
                if(maxi<0) return false;
            }
            if(mini==0) return true;
            return false;
    }
};