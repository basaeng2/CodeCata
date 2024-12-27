#include <iostream>
#include <string>
using namespace std;

int solution(int n) {
    string num = "";
    
    while (n > 0) {
        num += to_string(n % 3);
        n /= 3;
    }

    int answer = 0;
    int power = 1;
    for (int i = num.size() - 1; i >= 0; --i) {
        answer += (num[i] - '0') * power; 
        power *= 3; 
    }

    return answer;
}
