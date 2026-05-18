#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<unordered_set<int>> dp(9);
    
    for(int i = 1; i <= 8; i++)
    {
        string s = "";
        
        for(int k = 0; k < i; k++)
        {
            s += to_string(N);
        }
        
        dp[i].insert(stoi(s));
        
        for(int j = 1; j < i; j++)
        {
            for(int a : dp[j])
            {
                for(int b : dp[i - j])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    
                    if(b != 0)
                    {
                        dp[i].insert(a / b);
                    }
                }
            }
        }
        
        if(dp[i].find(number) != dp[i].end())
        {
            return i;
        }
    }    
    return -1;
}