#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i : scoville)
    {
        q.push(i);        
    }
    
    int count = 0;
    
    while(q.size() > 1 && q.top() < K)
    {
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        int newScovile = first + (second * 2);
        q.push(newScovile);
        count++;
    }
    
    if(!q.empty() && q.top() >= K)
    {
        return count;
    }
    else
    {
        return -1;
    }
}