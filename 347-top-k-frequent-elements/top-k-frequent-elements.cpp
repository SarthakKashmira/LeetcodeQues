class Solution {
public:
typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                mp[nums[i]]++;
            }
            else{
                mp.insert({nums[i],1});
            }
        }
        priority_queue<pi,vector<pi>,greater<pi>> minh;
        for(auto i:mp)
        {
            minh.push({i.second,i.first});
            if(minh.size()>k)
            {minh.pop();}
        }
        vector<int> ans;
        while(minh.size()>0)
        {ans.push_back(minh.top().second);
        minh.pop();
        }
        return ans;
    }
};