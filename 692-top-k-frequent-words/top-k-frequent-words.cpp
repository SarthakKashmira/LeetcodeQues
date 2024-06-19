class Solution {
public:
class compare{
    public:
        bool operator()(pair<int,string> pair1,pair<int,string> pair2){
          
            if(pair1.first != pair2.first)
                return pair1.first > pair2.first;
            else
                return pair1.second < pair2.second;
        }
    
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (const auto& word : words) { mp[word]++; }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> minh;
        for(auto i:mp)
        {    
             minh.push({i.second,i.first});
             if(minh.size()>k)
             {   minh.pop();}
        }
        vector<string> ans(k);
        int i=k-1;
        while(minh.size()>0)
        {
            ans[i]=minh.top().second;
            minh.pop();
            i--;
        }
        return ans;
    }
};