class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int n=nums.size();
        int end=0;
        int mx_len=0;
        int flipped_one=0;
        while(end<n){
            if(nums[end]==1)
                end++;
            else{
                if(flipped_one<k)
                {
                    flipped_one++;
                    end++;
                }else{
                    while(flipped_one==k){
                        if(nums[start]==0)
                            flipped_one--;
                        
                        start++;
                    }
                }
                
            }
            mx_len=max(mx_len,end-start);
        }
        return mx_len;
    }
};