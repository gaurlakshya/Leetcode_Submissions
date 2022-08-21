class Solution {
public:
    int longestseq(string s, int res, int k) {
    string x = "";
    // base case
    if(s.length() < k || s.length() == 0) return 0;

    map<char, int>m;
    for(int i = 0; i < s.length(); i++) {
        ++m[s[i]];
    }
  
    int flag = 1;
    for(int i = 0; i < s.length(); i++) {
        // breakpoint - if any character whose frequency is < k then send its left substring(x) where we might have frequency of every character >= k
        if(m[s[i]] < k) {
            flag = 0;
            //cout << x << endl;
            res = max(res, longestseq(x, res, k));
            x = "";
            continue;
        }
        x += s[i];
    }
    // if we dont hit the breakpoint then all the characters in the string s have frequency >= k - 2nd base case
    int total = 0;
    if(flag) { for (auto i : m) if(i.second >= k) total += i.second; return total; }
    res = max(res, longestseq(x, res, k)); // this call is for the right substring(of previous breakpoint) with no new breakpoint at the end Ex: "ababacbbbbbb" k=2, c is the break here
    return res; // return to main function

}
    int longestSubstring(string s, int k) {
        
        int len=s.length();
    if(len==0 || len < k) return 0;
    if(k<=1) return len;

    int res=0;
    res = longestseq(s, res, k);
        return res;
    }
};
