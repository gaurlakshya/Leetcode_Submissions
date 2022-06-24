// class Solution {
// public:
//     int clumsy(int n) {
//         int count=n-1;
//         int ans=n;
//         int val=0;
//         while(n){
//             switch(val){
//                 case 0:
//                     ans*=n-1;
//                     n--;
//                     val=(val+1)%4;
//                 break;
//                 case 1:
//                     if(n-1!=0)
//                     ans/=n-1;
//                      n--;
//                     val=(val+1)%4;
//                     break;
//                 case 2:
//                     ans+=n-1;
//                      n--;
//                     val=(val+1)%4;
//                     break;
//                 case 3:
//                     ans-=n-1;
//                      n--;
//                     val=(val+1)%4;
//                     break;
                    
//             }
                
            
//         }
//         return ans;
//     }
// };
#define MUL -1
#define DIV -2
#define ADD -3
#define SUB -4
class Solution {
public:
    int clumsy(int n) {
        /* 
            step1: construct vector<int> units due to the value of n. 
            According to the problem description, the value scope is in [1, 10000], 
            so we define the operator as:
            ops = -1: X, MUL
            ops = -2: /, DIV
            ops = -3: +, ADD
            ops = -4: -, SUB
            For example, as for n = 7, the vector<int> units is calculated as:
            [7, MUL, 6, DIV, 5, ADD, 4, SUB, 3, MUL, 2, DIV, 1, ]
            [7, -1,  6, -2,  5, -3,  4, -4,  3, -1,  2, -2,  1, ]
        */ 
        vector<int> units;
        units.push_back(n);
        int cur = n - 1;
        int ops = MUL;
        while(cur > 0){
            units.push_back(ops);
            units.push_back(cur);
            if (ops != SUB){ops = ops - 1;}
            else{ops = MUL;}
            cur = cur - 1;
        }
        /*
            step2: construct the stack stk from units, 
            for convenience i use a vector<int> instead of stack<int>
        */
        vector<int> stk;
        for (int i = 0; i < units.size(); i++){
            if (units[i] == MUL){
                stk.back() *= units[i + 1]; 
                i = i + 1;
                continue;
            }
            if (units[i] == DIV){
                stk.back() = stk.back() / units[i + 1];
                i = i + 1;
                continue;
            }
            stk.push_back(units[i]);
        }
        /* 
            step3: deal with ADD and SUB in the stack, 
            here we can reverse the sign of units[i + 1] if units[i] is SUB, 
            then add all the items of even index to get the result 
        */
        for (int i = 0; i < stk.size(); i++){
            if (stk[i] == SUB){
                stk[i + 1] = -stk[i + 1];
            }
        }
        int sum = 0;
        for (int i = 0; i < stk.size(); i = i + 2){
            sum += stk[i];
        }
        return sum;        
    }
};