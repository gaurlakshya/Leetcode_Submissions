class Solution {
public:
    void reverse(string &str){
        int n=str.length();
        int s=0;
        int e=n-1;
        while(s<=e){
            swap(str[s],str[e]);
            s++;e--;
        }
    }
    string convertToTitle(int columnNumber) {
      //  columnNumber-=1;
        string ans="";
        int n=columnNumber;
        while(n){
            n=n-1;
            int temp=n%26;
           // string val=
            ans.push_back('A'+temp);
            n/=26;
        }
        reverse(ans);
        return ans;
    }
};