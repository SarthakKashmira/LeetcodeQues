class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        while(n>0)
        {
            if((1 & n)==1)
            {
                count++;
                if(count>1) return false;
            }
            n=n>>1;
        }
        if(count)
        {
            return true;
        }
        return false;
    }
};