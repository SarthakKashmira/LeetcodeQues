class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto i:tokens)
        {
            if(i=="+")
            {
                int first=stoi(st.top());
                st.pop();
                int second=stoi(st.top());
                st.pop();
                
                st.push(to_string(second+first));
            }
            else if(i=="-")
            {
                int first=stoi(st.top());
                st.pop();
                int second=stoi(st.top());
                st.pop();
                st.push(to_string(second-first));
            }
            else if(i=="*")
            {
                int first=stoi(st.top());
                st.pop();
                int second=stoi(st.top());
                st.pop();
                st.push(to_string(second*first));
            }
            else if(i=="/")
            {
                int first=stoi(st.top());
                st.pop();
                int second=stoi(st.top());
                st.pop();
                st.push(to_string(second/first));
            }
            else{
                st.push(i);
            }
        }
        return stoi(st.top());;
    }
};