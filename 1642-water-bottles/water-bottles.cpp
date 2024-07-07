class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        ans=ans+numBottles;
        while(numBottles>=numExchange)
        {
            int change= numBottles/numExchange;
            ans+=change;
            int remain= numBottles%numExchange;
            numBottles=change+remain;
            
        }
           

        return ans;
    }
};