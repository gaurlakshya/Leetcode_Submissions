//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<string> exp;
    void solve(string s,int target,int index,string path,long int res,long int prev){
        if(index==s.size()){
            if(res==target) exp.push_back(path);
            return;
        }
        long int number=0;
        string substr="";
        for(int i=index;i<s.size();i++){
            substr+=s[i];
            number=(number*10)+s[i]-'0';
            if(substr.size()>1 && substr[0]=='0') break;
            if(index==0)
            solve(s,target,i+1,substr,number,number);
            else{
                solve(s,target,i+1,path+"+"+substr,res+number,number);
                solve(s,target,i+1,path+"-"+substr,res-number,-number);
                solve(s,target,i+1,path+"*"+substr,(res-prev)+(prev*number),(prev*number));
            }
        }
    }
    vector<string> addOperators(string s, int target) {
        // code here
        solve(s,target,0,"",0,0);
        return exp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends