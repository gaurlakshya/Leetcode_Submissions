//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
       unordered_map<char,int> ump;
       ump['I']=1;
       ump['V']=5;
       ump['X']=10;
       ump['L']=50;
       ump['C']=100;
       ump['D']=500;
       ump['M']=1000;
       int sum=0;
       int n=str.length();
       sum=ump[str[n-1]];
       for(int i=n-2;i>=0;i--){
           if(ump[str[i]]<ump[str[i+1]]) sum-=ump[str[i]];
           else
           sum+=ump[str[i]];
       }
       return sum;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends