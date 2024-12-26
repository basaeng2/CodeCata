#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int count = 0;
    for(int num : numbers)
    {
        answer += num;
        count++;
    }
    return answer / count;
}