class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
      while(j<nums.size()){
          if(nums[j]==0)
              j++;
          else
          {
              int temp= nums[j];
              nums[j]=nums[i];
              nums[i]=temp;
              i++;
              j++;
          }
      }
        
    }
};