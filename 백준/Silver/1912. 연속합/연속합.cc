#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n), dp(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        max_sum = max(max_sum, dp[i]);
    }

    cout << max_sum << "\n";
    return 0;
}