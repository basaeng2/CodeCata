#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    vector<int> digits;

    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    
    sort(digits.begin(), digits.end(), greater<int>());
    
    long long answer = 0;
    for (int digit : digits) {
        answer = answer * 10 + digit;
    }
    
    return answer;
}
