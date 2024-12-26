#include <cmath>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    int n = 1;
    long long sum = 0;
    while (n <= count)
    {
        sum += price * n;
        n++;
    }
    answer = money - sum;
    if(answer > 0) return 0;
    return abs(answer);
}