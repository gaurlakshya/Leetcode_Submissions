class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans1=-1,ans2=-1;
        if(high+1==0) return {-1,-1};
        //first ocucr.
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans1=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
                //second ocucr.
         low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans2=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return {ans1,ans2};
    }
};