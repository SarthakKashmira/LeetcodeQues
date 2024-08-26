class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int carry=0;
        int dig=digits[n]+1;
        n--;
        while((n)>=0 && dig>9)
        {
            digits[n+1]=dig%10;
            carry=1;
            dig=digits[n]+carry;
            n--;
        }
        if(dig>9)
        {
            digits[n+1]=dig%10;
            digits.insert(digits.begin(),1);
        }
        else{ digits[n+1]=dig; }
        return digits;

    }
};