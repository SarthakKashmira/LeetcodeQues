class Solution {
public:
   void solve(int start, int n, int k, vector<int> &temp, vector<vector<int>> &ans) {
    if (temp.size() == k) {
        ans.push_back(temp);
        return;
    }
    for (int i = start; i <= n; i++) {
        temp.push_back(i);
        solve(i + 1, n, k, temp, ans); // Move to the next element
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(1, n, k, temp, ans);  // Start from 1
    return ans;
}
};