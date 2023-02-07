//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end(),greater<int> ());
        sort(B.begin(),B.end(),greater<int> ());
        vector<int> ans;
        set<pair<int,int>> st;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({A[0]+B[0],{0,0}});
        
        for(int i=0;i<K;i++){
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.first);
            int idx1=p.second.first;
            int idx2=p.second.second;
            
            if(idx1+1<A.size() && st.find({idx1+1,idx2})==st.end()){
                pq.push({A[idx1+1]+B[idx2],{idx1+1,idx2}});
                st.insert({idx1+1,idx2});
            }
            if(idx2+1<B.size() && st.find({idx1,idx2+1})==st.end()){
                pq.push({A[idx1]+B[idx2+1],{idx1,idx2+1}});
                st.insert({idx1,idx2+1});
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends