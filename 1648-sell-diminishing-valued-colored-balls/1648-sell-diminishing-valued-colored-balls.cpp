#define mod 1000000007 
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n=inventory.size();
        long long res=0;
        sort(inventory.begin(),inventory.end());
        for(int i=n-1;i>=0;i--){
            long long diff=inventory[i]-(i>0?inventory[i-1]:0);
            long long x=min((long long)orders,(n-i)*diff);
            long long r=inventory[i];
            long long l=r-x/(n-i);
            res+=(r*(r+1)/2-l*(l+1)/2)*(n-i);
            res%=mod;
            res+=l*(x%(n-i));
            res%=mod;
            orders-=x;
        }
        return res;
    }
};