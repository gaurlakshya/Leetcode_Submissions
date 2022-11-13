class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
                   int cnt=0;

        for(int i=0;i<nums.size();i++){
            int val1=(nums[i]-k);
            int val2=k+nums[i];
            if(ump.find(val1)!=ump.end()) cnt+=ump[val1];
            if(ump.find(val2)!=ump.end()) cnt+=ump[val2];
            ump[nums[i]]++;
        }
        return cnt;
    }
};