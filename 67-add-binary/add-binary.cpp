class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int num=0;
        int siz1=a.size()-1;
        int siz2=b.size()-1;
        while(siz1>=0 && siz2>=0)
        {
            int num1=a[siz1]-'0';
            int num2=b[siz2]-'0';
            int sum=num+num1+num2;
            if(sum==0)
            {
                ans="0"+ans;
                num=0;
            }
            else if(sum==1)
            {
                ans="1"+ans;
                num=0;
            }
            else if(sum==2)
            {
                ans="0" + ans;
                num=1;
            }
            else{
                ans= "1" + ans;
                num=1;
            }
            siz1--;
            siz2--;
        }
        while(siz1>=0)
        {

            int num1=a[siz1]-'0';
            if((num1+num)==1)
            {
                ans="1"+ans;
                num=0;
            }
            else if((num1+num)==0)
            {
                ans="0"+ans;
                num=0;
            }
            else{
                ans="0"+ans;
                num=1;
            }
            siz1--;
        }
        while(siz2>=0)
        {
            int num1=b[siz2]-'0';
            if((num1+num)==1)
            {
                ans="1"+ans;
                num=0;
            }
            else if((num1+num)==0)
            {
                ans="0"+ans;
                num=0;
            }
            else{
                ans="0"+ans;
                num=1;
            }
            siz2--;
        }
        if(num==1)
        {ans="1"+ans;}
        return ans;

    }
};