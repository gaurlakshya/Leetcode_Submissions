class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
int ans=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> prev=intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prev[1]){
                ans++;
                if(intervals[i][1]<=prev[1])
                    prev=intervals[i];
            }else{
                prev=intervals[i];
            }
        }
        return ans;
    }
};