class Solution {
private:
    int catalan(int n, vector<int>& dp) {
        if (n <= 1) return 1;            
        if (dp[n] != -1) return dp[n];     

        long long result = 0;
        for (int i = 0; i < n; i++) {
            result += (long long)catalan(i, dp) * catalan(n - i - 1, dp);
        }

        return dp[n] = (int)result;      
    }

public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);        
        return catalan(n, dp);
    }
};
