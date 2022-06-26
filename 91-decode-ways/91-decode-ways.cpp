class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> vec(n+1,0);
        vec[0]=1;
        if(s[0]=='0')
            vec[1]=0;
        else
            vec[1]=1;
        for(int i=2;i<=n;i++){
            int one_digit=s[i-1]-'0';
            int combined=10*(s[i-2]-'0')+one_digit;
            if(one_digit>0)
                vec[i]+=vec[i-1];
            if(combined>9 && combined<=26)
                vec[i]+=vec[i-2];
        }
        return vec[n];
    }
};