class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>> v;
        int ans=0;
        for(auto i:timePoints)
        {
            string str1=i.substr(0,2);
            string str2=i.substr(3,2);
            int n1=stoi(str1);
            int n2=stoi(str2);
            v.push_back({n1,n2});
        }
     
        sort(v.begin(),v.end());
        int siz=v.size();
        pair<int,int> p1=v[0];
        pair<int,int> p2=v[siz-1];
        ans=ans+60-p2.second;
        ans=ans+(23-p2.first+p1.first)*60;
        ans=ans+p1.second;
        for(auto i=1;i<siz;i++)
        {
            pair<int,int> p4=v[i];
            pair<int,int> p3=v[i-1];
            int tempans=0;
            if(p3.first==p4.first)
            {
              tempans=p4.second-p3.second;
            }else{
              tempans=tempans+60-p3.second;
              tempans=tempans+(p4.first-p3.first-1)*60;
              tempans=tempans+p4.second;
            }
            ans=min(ans,tempans);
        }
        return ans;

    }
};