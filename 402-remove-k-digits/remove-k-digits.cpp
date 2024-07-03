class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        int count=k;
       stack<char> st;
       for (char digit : num) {
          while (!st.empty() && count > 0 && st.top() > digit) {
            st.pop();
            count--;
          }
        st.push(digit);
       }
        while(count!=0 ){
            st.pop();
            count--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int i=ans.size()-1;
        while(i>=0 && ans[i]=='0')
        {
            ans.pop_back();
            i--;
        }
        if(ans.size()==0){return "0";}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};