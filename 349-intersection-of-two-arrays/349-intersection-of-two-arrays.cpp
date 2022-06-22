class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1;
        for(int i=0;i<nums1.size();i++){
            us1.insert(nums1[i]);
        }
        unordered_set<int> us2;
        for(int j=0;j<nums2.size();j++)
            us2.insert(nums2[j]);
        vector<int> ans;
        for(auto it:us1){
            if(us2.find(it)!=us2.end())
                ans.push_back(it);
        }
        return ans;
    }
};