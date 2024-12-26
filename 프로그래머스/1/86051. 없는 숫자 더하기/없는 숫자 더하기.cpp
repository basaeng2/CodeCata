#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> A(10);
    sort(numbers.begin(),numbers.end());
     for(int i = 0; i < 10; i++)
    { 
         A[i] = i;
    }
    for(int i = 0; i < numbers.size(); i++)
    {
        A[numbers[i]] = 0;
    }
    for(int i = 0; i < A.size(); i++)
    {
        answer += A[i];
    }
    return answer;
}