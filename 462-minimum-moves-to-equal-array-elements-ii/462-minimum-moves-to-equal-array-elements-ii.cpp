class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        int count=0;
        int e=nums.size()-1;
        while(s<e){
            count+=(nums[e]-nums[s]);
            s++;
            e--;
        }
        return count;
    }
};