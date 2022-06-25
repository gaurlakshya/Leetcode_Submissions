class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> vec(n,false);
        
        int val=sqrt(n);
        for(int i=2;i<=val;i++){
            if(vec[i]==false)
                for(int j=i*i;j<n;j+=i)
                    vec[j]=true;
        }
        int count=0;
        for(int i=2;i<n;i++)
            if(vec[i]==false)
                count++;
        return count;
    }
};