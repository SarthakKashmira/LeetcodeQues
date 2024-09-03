class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
    vector<int> nextgreat(n, n);  
    vector<int> prevgreat(n, -1); 
    stack<int> st;

    // Calculate next smaller elements
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            nextgreat[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Clear the stack for re-use
    while (!st.empty()) st.pop();

    // Calculate previous smaller elements
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            prevgreat[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Calculate the maximum area
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int width = nextgreat[i] - prevgreat[i] - 1;
        int area = heights[i] * width;
        ans = max(ans, area);
    }

    return ans;
    }
};