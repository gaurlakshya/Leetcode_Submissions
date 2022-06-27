class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> vec;
        vec.push_back(intervals[0]);
        vector<int> prev=intervals[0];
        int n=intervals.size();
        for(int i=1;i<n;i++){
          vector<int> curr=intervals[i];
            //merged
            if(curr[0]<=prev[1] && prev[0]<=curr[0]){
                vec.pop_back();
                prev[1]=max(curr[1],prev[1]);
                vec.push_back(prev);
            }else{
                //not merged
                vec.push_back(curr);
                prev=curr;
            }
        }
        return vec;
    }
};