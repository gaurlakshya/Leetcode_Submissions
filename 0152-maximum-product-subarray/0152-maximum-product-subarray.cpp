class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int mn=res;
        int mx=res;
        
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(mx,mn);
            mx=max(nums[i],nums[i]*mx);
            mn=min(nums[i],nums[i]*mn);
            res=max(res,mx);
        }
        return res;
    }
};