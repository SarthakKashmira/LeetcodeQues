class Solution {
public:
    int findTheWinner(int n, int k) {
        int count=0;
        vector<int> v;
        for(int i=1;i<=n;i++){v.push_back(i);cout<<v[i-1];}
        int j=0;
        while (v.size() > 1) {
        j = (j + k-1) % v.size();
        v.erase(v.begin() + j);
        }
        return v[0];
    }
};