class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res=0;
        for(int i=0 ;i<32;i++){
            int t=n&1;
            int ans=t<<(31-i);
            res=res|ans;
            n=n>>1;
        }
        return res;
    }
};