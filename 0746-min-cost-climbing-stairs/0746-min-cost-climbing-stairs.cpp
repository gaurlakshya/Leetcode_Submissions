class Solution {
public:
  
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       int prev=cost[1];
        int prev_prev=cost[0];
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev,prev_prev);
            prev_prev=prev;
            prev=curr;
        }
        return min(prev,prev_prev);
    }
};