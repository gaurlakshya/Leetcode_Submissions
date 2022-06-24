class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int ans=0;
        if(n==1)
            return columnTitle[0]-'A'+1;
        else{
            int temp=0;
            for(int i=0;i<n;i++){
             temp=pow(26,n-i-1);
                temp*=(columnTitle[i]-'A'+1);
                ans+=temp;
            }
        }
        return ans;
    }
};