class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
int slen=s.length();
        int plen=p.length();
        if(s.size()<p.size()) return {};
        vector<int> freq_p(26,0);
        vector<int> freq_s(26,0);
        
        for(int i=0;i<plen;i++){
            freq_p[p[i]-'a']++;
            freq_s[s[i]-'a']++;
        }
        vector<int> res;
        if(freq_p==freq_s) res.push_back(0);
        for(int i=plen;i<slen;i++){
            freq_s[s[i-plen]-'a']--;
            freq_s[s[i]-'a']++;
             if(freq_p==freq_s) res.push_back(i-plen+1);
            
        }
        return res;
    }
};

        
