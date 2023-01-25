//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int row, int col, int size){
        if(size==word.size()) return true;
        if(row<0 || row>=board.size() || col<0 || col>=board[row].size() || board[row][col]!=word[size]) return false;
        char ch=board[row][col];
        board[row][col]='.';
        int a=dfs(board,word,row-1,col,size+1);
        int b=dfs(board,word,row,col+1,size+1);
        int c=dfs(board,word,row+1,col,size+1);
        int d=dfs(board,word,row,col-1,size+1);
        board[row][col]=ch;
        return a|| b||c||d;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends