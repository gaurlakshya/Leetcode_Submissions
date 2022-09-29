class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int total=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> prev=intervals[0];
        for(int i=1;i<n;i++){
            vector<int> curr=intervals[i];
            if(curr[0]<prev[1]){
                total++;
                if(curr[1]<=prev[1])
                    prev=curr;
            }else
                prev=curr;
            
        }
        return total;
    }
};