class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int l=n-1;
        int carry=0;
        int count=0;
        for (int i = n - 1; i > 0; --i) {
        if (s[i] == '0' + carry) {
            count += 1;
        } else {
            carry = 1;
            count += 2;
        }
    }

    if (carry == 1) {
        count += 1;
    }
        return count;
    }
};