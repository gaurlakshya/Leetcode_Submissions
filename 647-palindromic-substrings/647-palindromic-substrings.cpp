class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int res=0;
        vector<vector<bool>> table(n,vector<bool>(n,false));
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=diff;j<n;i++,j++){
                if(diff==0)
                    table[i][j]=true;
                else if(diff==1){
                    if(s[i]==s[j])
                        table[i][j]= true;
                }else{
                    if(s[i]==s[j])
                        table[i][j]=table[i+1][j-1];
                }
                if(table[i][j]) res++; 
            }
        }
        return res;
    }
};