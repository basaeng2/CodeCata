#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    dp[1][1] = 1;
    
    for (const auto& puddle : puddles) {
        dp[puddle[1]][puddle[0]] = -1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 1) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    
    return dp[n][m];
}
