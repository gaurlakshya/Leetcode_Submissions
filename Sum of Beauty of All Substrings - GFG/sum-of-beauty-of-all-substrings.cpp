//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
         int ans=0;
       
        int n=s.length();
        for(int i=0;i<n;i++){
                vector<int> cnt(26,0);
                int mx=INT_MIN;
                int mn=INT_MAX;
            for(int j=i;j<n;j++){
                int index=s[j]-'a';
                cnt[index]++;
                mx=max(mx,cnt[index]);
                mn=cnt[index];
                for(int k=0;k<26;k++){
                if(cnt[k]>=1)
                    mn=min(mn,cnt[k]);
                }
                ans+=mx-mn;    
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends