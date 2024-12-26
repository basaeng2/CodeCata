#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long i = 0;
    while (i * i <= n) {
        if (++i * i == n) {
            return (i + 1) * (i + 1);
        }
    }
    return -1;
}
