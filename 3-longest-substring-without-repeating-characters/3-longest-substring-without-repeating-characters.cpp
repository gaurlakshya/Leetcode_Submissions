class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans;
        int st=0,en=0;
        int n=s.size();
        unordered_map<int,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            while(mp[s[i]-'a']>1){
                ans=max(ans,i-st);
                mp[s[st]-'a']--;
                st++;
            }
        }
        ans=max(ans,n-st);
        return ans;
    }
};