class Solution {
public:
    int passThePillow(int n, int time) {
        int onetime=n-1;
        int ForL=time%onetime;
        if(ForL==0)
        {
            if((time/onetime)%2==0) return 1;
            else{return n;
            }
        }
        else{
            int ans=time/onetime;
            if(ans%2==0) return ForL+1;
            else{return n-ForL;}
        }
        return -1;
    }
};