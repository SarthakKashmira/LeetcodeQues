class Solution {
public:
    int myAtoi(string s) {
        long long ret=atol(s.c_str());
        ret=ret>INT_MAX?INT_MAX:ret;
        ret=ret<INT_MIN?INT_MIN:ret;
        return ret;
    }
};