#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<string> arr)
{
    vector<int> nums;
    vector<char> ops;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
            nums.push_back(stoi(arr[i]));
        else
            ops.push_back(arr[i][0]);
    }

    int n = nums.size();

    vector<vector<int>> maxDp(n, vector<int>(n, INT_MIN));
    vector<vector<int>> minDp(n, vector<int>(n, INT_MAX));

    // 길이 1 초기화
    for (int i = 0; i < n; i++)
    {
        maxDp[i][i] = nums[i];
        minDp[i][i] = nums[i];
    }

    // 구간 길이
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;

            for (int k = i; k < j; k++)
            {
                char op = ops[k];

                if (op == '+')
                {
                    maxDp[i][j] = max(maxDp[i][j], maxDp[i][k] + maxDp[k + 1][j]);
                    minDp[i][j] = min(minDp[i][j], minDp[i][k] + minDp[k + 1][j]);
                }
                else // '-'
                {
                    maxDp[i][j] = max(maxDp[i][j], maxDp[i][k] - minDp[k + 1][j]);
                    minDp[i][j] = min(minDp[i][j], minDp[i][k] - maxDp[k + 1][j]);
                }
            }
        }
    }

    return maxDp[0][n - 1];
}