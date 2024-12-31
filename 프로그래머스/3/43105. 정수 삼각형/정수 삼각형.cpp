#include <string>
#include <vector>
#include <algorithm>  // max 함수 사용

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp = triangle;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}
