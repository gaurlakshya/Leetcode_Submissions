class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int n=customers.size();
        int s=0;
        int e=0;
        int win_sum=0;
        int max_win=0;
        int total=0;
        while(e<n){
            if(grumpy[e]==0) total +=customers[e];
            if(grumpy[e]==1) win_sum+=customers[e];
            int win_size=e-s+1;
            if(win_size>minutes){
                if(grumpy[s]==1) win_sum-=customers[s];
                s++;
            }
            e++;
            max_win=max(max_win,win_sum);
        }
        return total +max_win;
    }
};
