#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> processQueue;
    priority_queue<int> priorityOrder;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        processQueue.push({priorities[i], i});
        priorityOrder.push(priorities[i]);
    }

    while (!processQueue.empty())
    {
        int currentPriority = processQueue.front().first;
        int currentIndex = processQueue.front().second;
        processQueue.pop();

        if (currentPriority == priorityOrder.top())
        {
            answer++;
            priorityOrder.pop();
            
            if (currentIndex == location)
            {
                return answer;
            }
        } else {
            processQueue.push({currentPriority, currentIndex});
        }
    }
    
    return answer;
}
