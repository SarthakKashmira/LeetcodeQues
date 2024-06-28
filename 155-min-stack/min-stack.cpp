class MinStack {
    stack<pair<int,int>> st;
    int min;
public:
    MinStack() {
        min=2147483647;
    }
    
    void push(int val) {
        if(val<min){min=val;}
        st.push({val,min});
    }
    
    void pop() {
       st.pop();
       if(!st.empty())
       min=st.top().second;
       else{
        min=2147483647;
       }
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */