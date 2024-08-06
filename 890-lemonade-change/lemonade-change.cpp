class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ten=0;
        int five=0;
        for(auto i:bills)
        {
            
            if(i>5)
            {
               if(i==10)
               {
                ten++;
                if(five<1) return false;
                five--;
               }
               else if(i==20)
               {
                if((five<1 || ten<1) && five<3) return false;
                if(ten>=1){five--;ten--;}
                else{
                    five-=3;
                }
               }
            }
            else{
                five++;
            }
        }
        return true;        
    }
};