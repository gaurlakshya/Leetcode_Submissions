class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(i==0) if(s[i]!=' ')count=1;
            else continue;
           else if(s[i-1]==' ' && s[i]!=' ')
                count=1;
            else if(s[i]!=' ')
                count++;
        }
        return count;
    }
};