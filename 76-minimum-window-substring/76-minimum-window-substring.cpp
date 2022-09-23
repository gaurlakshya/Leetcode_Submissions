class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        string ans;
        int n_s=s.size();
        int n_t=t.size();
        vector<int> freq(128,0);
        for(int i=0;i<n_t;i++)
            freq[t[i]]++;
        int count=t.size();
        int st=0,en=0,minlen=INT_MAX,minStart=0;
        while(en<s.size()){
            char  temp=s[en];
            if(freq[temp]>0) count--;
            freq[temp]--;
            en++;
            while(count==0){
                if(minlen>en-st)
                {
                    minStart=st;
                    minlen=en-st;
                }
                freq[s[st]]++;
                if(freq[s[st]]>0) count++;
                st++;
            }
        }
        return minlen==INT_MAX ?"":s.substr(minStart,minlen);
    }
};