class Solution {
public:
    bool isPowerOfFour(int n) {
        int count=0;
        int index=0;
        int indexOfOne=0;
        while(n>0)
        {
            if((n&1)==1)
            {
                count++;
                indexOfOne=index;
                if(count>1) return false;
            }
            n=n>>1;
            index++;
        }
        if(count==1 && (indexOfOne & 1)==0) return true;
        return false;
    }
};