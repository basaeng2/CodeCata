#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;  // 작업 횟수 초기화
    long n = num;
    while (n != 1) {  // 수가 1이 될 때까지 반복
        if (answer >= 500) {  // 500번 이상 반복한 경우
            return -1;
        }
        if (n % 2 == 0) {  // 짝수일 경우
            n /= 2;
        } else {  // 홀수일 경우
            n = n * 3 + 1;
        }
        answer++;  // 작업 횟수 증가
    }
    return answer;  // 1에 도달한 횟수 반환
}
