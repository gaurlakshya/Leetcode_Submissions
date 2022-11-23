class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frq(128,0);
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2) return false;
        
        for(int i=0;i<n1;i++){
            frq[s[i]-' ']++;
        }
        
        for(int i=0;i<n2;i++){
            frq[t[i]-' ']--;
        }
        
        for(int i=0;i<128;i++){
            if(frq[i]!=0) return false;
        }
        return true;
    }
};