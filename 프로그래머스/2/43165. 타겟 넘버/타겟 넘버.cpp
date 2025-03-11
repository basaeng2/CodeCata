#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int>& numbers, int target, int index, int sum, int& count)
{
    if(index == numbers.size())
    {
        if(sum == target)
        {
            count++;
        }
        return;
    }
    
    DFS(numbers, target, index + 1, sum + numbers[index], count);
    DFS(numbers, target, index + 1, sum - numbers[index], count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, target, 0, 0, answer);
    return answer;
}