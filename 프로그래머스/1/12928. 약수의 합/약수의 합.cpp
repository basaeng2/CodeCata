#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    // n의 약수를 찾고 더함
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {  // n을 i로 나누었을 때 나머지가 0이면 약수
            answer += i;
        }
    }
    
    return answer;
}
