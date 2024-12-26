#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 1; i <= n; ++i) {
        answer.push_back(static_cast<long long>(x) * i);
    }
    
    return answer;
}
