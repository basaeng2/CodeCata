#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int MOD = 1234567;
    vector<int> DP(100001, 0);
    
    DP[0] = 0;
    DP[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
    }
    
    answer = DP[n];
    
    return answer;
}