class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        while(n!=1){
            int j=0;
        for(int i=0;i<n;i+=2){
            if(flag){
                nums[j++]=min(nums[i],nums[i+1]);
            }else{
                nums[j++]=max(nums[i],nums[i+1]);
            }
            flag=!flag;
        }
            n=n/2;
        }
        return nums[0];
    }
};