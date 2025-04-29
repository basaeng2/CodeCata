#include <iostream>
#include <vector>
using namespace std;

long long solution(int N) {
    vector<long long> count(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            count[j] += i;
        }
    }

    // g(N)은 모든 f(i)의 합
    long long result = 0;
    for (int i = 1; i <= N; i++) {
        result += count[i];
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << solution(N) << '\n';

    return 0;
}

/*
i = 1
count[1] += 1;
count[2] += 1;
count[3] += 1;
count[4] += 1;
count[5] += 1;
count[6] += 1;

i = 2
count[2] += 2;
count[4] += 2;
count[6] += 2;

i = 3
count[3] += 3;
count[6] += 6;

i = 4
count[4] += 4;

i = 5
count[5] += 5;

i = 6
count[6] += 6;
*/