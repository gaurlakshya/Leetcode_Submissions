class Solution {
private:
    string countOneS(string& s){
        char prev_c = s[0];
        int count = 0;
        string ans;
        for (char c:s){
            if (c == prev_c){
                count++;
            }
            else{
                ans += to_string(count) + prev_c;
                count = 1;
                prev_c = c;
            }
        }
        ans += to_string(count) + s[s.size()-1];
        return ans;
    }
    
public:
    string countAndSay(int n) {
        string tmp_s = "1";
        if (n==1) return tmp_s;
        for (int i=1;i<n;i++){
            tmp_s = countOneS(tmp_s);
            //cout<<tmp_s;
        }
        return tmp_s;
    }
};