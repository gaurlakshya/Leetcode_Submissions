//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int len=s.length();
		    vector<int> vec(26,0);
		    int mxcount=0;
		    int start=0;
		    int ans=0;
		    
		    for(int i=0;i<len;i++){
		        vec[s[i]-'A']++;
		        if(mxcount <vec[s[i]-'A']) mxcount=vec[s[i]-'A'];
		        while(i-start+1-mxcount>k){
		            vec[s[start]-'A']--;
		            start++;
		            for(int i=0;i<26;i++){
		                if(mxcount<vec[i]) mxcount=vec[i];
		            }
		        }
		        ans=max(ans,i-start+1);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends