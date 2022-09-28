class Solution {
public:
    bool static cmp(pair<int,int> &a,pair<int,int>&b){
        if(a.second < b.second) return true;
        else if(a.second == b.second) return a.first > b.first;
        return false;
    }
   
       vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        vector<pair<int, int>> v;
        for(auto i : m)
            v.push_back(i);
        
        //Sort by [value/second of pair] in ascending order
        sort(v.begin(), v.end(), cmp);
        
        vector<int> res;
        for(int i=0; i<v.size(); i++){
            int cnt = v[i].second;
            for(int j=0; j<cnt; j++)
                res.push_back(v[i].first);
        }
        return res;
    }
};