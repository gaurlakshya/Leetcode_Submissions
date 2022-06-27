class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = -1;
        int sum = 0;
        for(int i:nums)
            sum+=i;
        int left = 0, right = sum;
        for(int i=0; i<nums.size(); i++)
        {
            left = (i==0)? 0:left + nums[i-1];
            right = right-nums[i];
            if(right==left)
                return i;
        }
        return pivot;
    }
};