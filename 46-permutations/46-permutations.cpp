class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&res,vector<int> ans,int freq[]){
        if(ans.size()==nums.size()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]!=1){
                ans.push_back(nums[i]);
                freq[i]=1;
                solve(nums,res,ans,freq);
                freq[i]=0;
                ans.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        solve(nums,res,ans,freq);
        return res;
    }
};