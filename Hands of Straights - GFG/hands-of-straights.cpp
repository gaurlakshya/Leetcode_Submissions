//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) {
        // code here
        if(floor(n/groupSize)!=ceil(n/groupSize)) return false;
       priority_queue<int,vector<int>,greater<int>> pq;
       for(int i=0;i<n;i++) pq.push(hand[i]);
       while(!pq.empty()){
                 int prev=pq.top()-1;
                for(int i=0;i<groupSize;i++){
                  int  curr=pq.top();
                   pq.pop();
                    if( prev<curr-1) return false;
                   prev=curr;
                }
       }
       return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends