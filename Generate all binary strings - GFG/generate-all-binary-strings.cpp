//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(int n,string ans,string prev){
        if(n<0) return;
        if(n==0){
            cout<<ans<<" ";
            return;
        }
        if(prev=="1"){
                     ans.push_back('0');
            solve(n-1,ans,"0");
            ans.pop_back();
        }
        else{
         ans.push_back('0');
         solve(n-1,ans,"0");
         ans.pop_back();
         ans.push_back('1');
         solve(n-1,ans,"1");
    }
    }
    void generateBinaryStrings(int& num){
        //Write your code
        int n=num;
        string ans="";
        solve(n,ans,"-1");
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends