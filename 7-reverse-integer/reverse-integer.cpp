class Solution {
public:
    int reverse(int x) {
        int ans=0;
        bool flag=false;
        if(x<0){
            long long int temp=(long long)(x)*(-1);
            if(temp>INT_MAX) return 0;
            x=(-1)*x;
            flag=true;
        }
        if(x>=INT_MAX) return 0;
        while(x>0)
        {
            int dig=x%10;
            x=x/10;
            long long int temp=(long long)(ans)*10;
            if(temp>INT_MAX) return 0;
            ans=(ans*10) + dig;
        }
        if(flag) return (-1)*ans;
        return ans;
    }
};