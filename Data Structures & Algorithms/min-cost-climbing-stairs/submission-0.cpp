#include<cstring>
class Solution {
public:
    int t[101];
    int solve(vector<int>&cost,int i){
        int n = cost.size();
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
       
        t[i] = cost[i] + min(solve(cost,i+1) , solve(cost,i+2));
        
        return t[i];
       


    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        return min (solve(cost,0), solve(cost,1));

        
    }
};
