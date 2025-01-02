#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int lastPainted = 0;
    
    for (int num : section) {
        if (num > lastPainted) { 
            lastPainted = num + m - 1;
            answer++;
        }
    }
    return answer;
}
