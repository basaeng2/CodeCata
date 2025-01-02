#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = i + 1; j < nums.size(); j++) {
            for (size_t k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (isPrime(sum)) {
                    answer++;
                }
            }
        }
    }

    return answer;
}
