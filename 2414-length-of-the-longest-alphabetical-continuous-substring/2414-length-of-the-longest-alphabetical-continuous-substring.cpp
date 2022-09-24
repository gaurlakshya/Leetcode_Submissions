class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = INT_MIN , maxi = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1]+1 == s[i])    maxi++;
            else{
                ans = max(ans,maxi);
                maxi = 1;
            }
        }
        return max(ans,maxi);
    }
};