class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int canReachable=0;
        for(int i=0;i<n;i++){
            if(i>canReachable) return false;
            canReachable=max(canReachable,i+nums[i]);
        }
        return true;
    }
};