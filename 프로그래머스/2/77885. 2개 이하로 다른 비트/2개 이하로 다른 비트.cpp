#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long x : numbers)
    {
        if (x % 2 == 0)
        {
            // 짝수면 +1만 하면 비트 1개 차이
            answer.push_back(x + 1);
        }
        else
        {
            // 홀수면 가장 낮은 자리의 0을 1로, 그 다음 1을 0으로
            // 0111
            // 1000
            //  100
            long long bit = 1;
            while ((x & bit) != 0)
            {
                bit <<= 1;
            }
            long long next = x + bit - (bit >> 1);
            answer.push_back(next);
        }
    }
    return answer;
}
