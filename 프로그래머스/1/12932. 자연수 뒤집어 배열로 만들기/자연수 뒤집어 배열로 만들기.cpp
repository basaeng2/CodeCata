#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
    vector<int> result;
    
    while (n > 0) {
        result.push_back(n % 10);
        n /= 10;
    }
    
   return result;
}