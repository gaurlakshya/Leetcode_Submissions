class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int xor_value=0;
        // for(int i=0;i<nums.size();i++){
        //     xor_value^=nums[i];
        // }
        // return xor_value;
        int s=0;
        int n=nums.size();
        int e=n-1;
        int mid=0;
        while(s<=e){
            mid=s+(e-s)/2;
            bool length_even=(mid-s)%2==0;
            if(mid+1<n && nums[mid]==nums[mid+1]){
                if(length_even)
                    s=mid+2;
                else
                    e=mid-1;
            }
           else if(mid>s && nums[mid]==nums[mid-1]){
                if(length_even)
                    e=mid-2;
                else
                    s=mid+1;
             
               
            }
             else  return nums[mid];
        }
        return -1;
    }
};