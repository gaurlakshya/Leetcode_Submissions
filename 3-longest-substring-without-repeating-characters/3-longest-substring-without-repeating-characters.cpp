class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=INT_MIN;
        int n=s.length();
        int start=0;
        unordered_map<char,int> ump;
        for(int i=0;i<n;i++){
            ump[s[i]]++;
            while(ump[s[i]]>1){
                res=max(res,i-start);
                ump[s[start]]--;
                start++;
            }
        }
        res=max(res,n-start);
        return res;
    }
};