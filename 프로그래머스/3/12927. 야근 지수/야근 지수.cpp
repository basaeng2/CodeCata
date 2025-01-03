#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> MaxHeap(works.begin(), works.end());
    
    while(n > 0 && !MaxHeap.empty())
    {
        int top = MaxHeap.top();
        MaxHeap.pop();
        if(top > 0)
        {
            top--;
            n--;
            MaxHeap.push(top);
        }
        else
        {
            break;
        }
    }
    
    while(!MaxHeap.empty())
    {
        int work = MaxHeap.top();
        MaxHeap.pop();
        answer += pow(work, 2);
    }
    
    return answer;
}