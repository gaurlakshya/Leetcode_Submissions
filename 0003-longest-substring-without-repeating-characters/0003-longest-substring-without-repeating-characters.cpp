class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=INT_MIN;
        int n=s.length();
map<char,int> mp;
        
    int i=0;
        int e=0;
        for(e=0;e<n;e++){
            mp[s[e]]++;
            ans=max(ans,e-i);
            while(mp[s[e]]>1){
                mp[s[i]]--;
                i++;
            }
        }
        if(e-i>ans) return e-i;
        return ans;
    }
};