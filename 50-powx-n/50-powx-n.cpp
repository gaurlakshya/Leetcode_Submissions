class Solution {
public:
    double myPow(double x, int n) {
     double ans=1.0;
      long long int n1=n;
        double temp=x;
        if(n1<0) n1=n1*-1;
        while(n1){
            if(n1%2){
                ans*=x;
                n1--;;
            }
            else{
                n1/=2;
                x=x*x;
            }
        }
        if(n<0) ans= 1.0/ans;
        return ans;
    }
};