#include<cstring>

class Solution {
public:
    int t[101];
    int solve(string &s, int i) {
        int n = s.length();

        
        if (i == n)
            return 1;

        
        if (s[i] == '0')
            return 0;
        
        if(t[i]!=-1){
            return t[i];
        }

       
        int ans = solve(s, i + 1);

        
        if (i + 1 < n &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ans += solve(s, i + 2);
        }

        return t[i] = ans;
    }

    int numDecodings(string s) {
        memset(t, -1, sizeof(t));
        return solve(s, 0);
    }
};