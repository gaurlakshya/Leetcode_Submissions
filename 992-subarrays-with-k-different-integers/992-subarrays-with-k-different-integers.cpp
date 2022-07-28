class Solution {
public:
     int solve(vector<int> &nums, int k)
    {
        if(k==0)
            return 0;
        unordered_map <int,int> mp;
        int n = nums.size(), left = 0, total = 0, diff = 0;
        for(int right = 0;right<n;right++)
        {
            if(mp[nums[right]] == 0)
                diff++;
            mp[nums[right]]++;
            while(left<n and diff>k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    diff--;
                left++;
            }
            total+=right-left+1;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return solve(nums, k) - solve(nums, k-1);
    }
};