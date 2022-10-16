class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> vec(s.size(),vector<bool>(s.size(),false));
        int count=0;
        for(int diff=0;diff<s.size();diff++){
            for(int i=0,j=diff;j<s.size();j++,i++){
                if(diff==0)
                    vec[i][j]=true;
                else if(diff==1){
                    if(s[i]==s[j])
                        vec[i][j]=true;
                }
                else{
                    if(s[i]==s[j]){
                        vec[i][j]=vec[i+1][j-1];
                    }
                }
                 if(vec[i][j]) count++;
            }
           
        }
        return count;
    }
};