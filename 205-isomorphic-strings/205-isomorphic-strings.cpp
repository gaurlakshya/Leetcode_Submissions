class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m) return false;
        vector<int> vec1(128,0);
        vector<int> vec2(128,0);
        for(int i=0;i<n;i++){
            if(vec1[s[i]]==0 && vec2[t[i]]==0){
                vec1[s[i]]=t[i];
            vec2[t[i]]=1;
            }
            else if(vec1[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};