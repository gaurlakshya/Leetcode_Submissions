class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> ump;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(ump[nums[i]])
                count+=ump[nums[i]];
            ump[nums[i]]++;
        }
        return count;
    }
};