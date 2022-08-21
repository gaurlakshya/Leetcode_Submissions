class Node{
    public:
        int data;
        int row;
        int col;
    Node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};

class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data >b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        priority_queue<Node *,vector<Node*>,compare> pq;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int curr=nums[i][0];
            mini=min(mini,curr);
            maxi=max(maxi,curr);
            pq.push(new Node(curr,i,0));
        }
        int start=mini,end=maxi;
        while(!pq.empty()){
            Node* curr=pq.top();
            pq.pop();
            int least=curr->data;
            int row=curr->row;
            int col=curr->col;
            mini=least;
            if(maxi-mini < end-start){ start=mini;
                                     end=maxi;}
            if(col+1<nums[row].size()){
                maxi=max(maxi,nums[row][col+1]);
                pq.push(new Node(nums[row][col+1],row,col+1));
            }else break;
        
        }
        return {start,end};
    }
};