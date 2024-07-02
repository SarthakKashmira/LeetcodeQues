class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        cout<<"Hello"<<endl;
        for(int i=asteroids.size()-1;i>=0;i--)
        {
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else if(asteroids[i]>=0 && st.top()>=0)
            {
                st.push(asteroids[i]);
            }
            else if(asteroids[i]<0 && st.top()<0)
            {
                st.push(asteroids[i]);
            }
            else if(st.top()>=0 && asteroids[i]<0)
            {st.push(asteroids[i]);}
            else{
                int n=asteroids[i];
                
                     int count=0;
                     while(!st.empty() && ((st.top()<0 && n>=0) ))
                    { 
                        if((-1*n)==st.top())
                        {st.pop();
                        count=1;
                        break;}
                        cout<<n;
                        int x=st.top();
                        st.pop();
                        if(n<0) {   if((-1*n)<x) { n=x;} }
                        if(x<0) { if((-1*x)>n){ n=x; cout<<n;}  }
                    }
                    if(count==0)
                    {st.push(n);}
                
            }
        }
        while(!st.empty())
        {ans.push_back(st.top());
        st.pop();
        }
        return ans;
    }
};