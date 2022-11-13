class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int n=nums.size();
        int mx=0;
for(auto n:nums) us.insert(n);
        for(int i=0;i<n;i++){
            int cur_val=nums[i];
            if(us.find(cur_val-1)==us.end()){
                        int curr=1;

                while(us.count(cur_val+1)){
                    cur_val+=1;
                    curr++;
                }
                            mx=max(mx,curr);

            }
        }
        return mx;
    }
};