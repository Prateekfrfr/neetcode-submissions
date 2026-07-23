#include <cstring>

class Solution {
public:
    int t[46];
    int ways(int n){
        if(n==0||n==1){
            return 1;
        }
        if(t[n]!=-1){
            return t[n];
        }
        return t[n] = ways(n-1) + ways(n-2);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return ways(n);
        
    }
};
