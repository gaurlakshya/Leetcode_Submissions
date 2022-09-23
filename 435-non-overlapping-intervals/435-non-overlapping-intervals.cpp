class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> prev=intervals[0];
        for(int i=1;i<n;i++){
            if(prev[1]>intervals[i][0]){
                count++;
                if(intervals[i][1]<=prev[1])
                    prev=intervals[i];
            }else
                prev=intervals[i];
        }
        return count;
        
    }
};