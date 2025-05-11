#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    
    queue<pair<int,int>> q;
    unordered_set<int> visited;
    
    q.push({x,0});
    visited.insert(x);
    
    while(!q.empty())
    {
        pair<int,int> node = q.front();
        int current = node.first;
        int count = node.second;
        
        q.pop();
        
        if(current == y)
        {
            return count;
        }
        
        int next_value[] = {current + n, current * 2, current * 3};
        for(int next : next_value)
        {
            if(next <= y && visited.find(next) == visited.end())
            {
                visited.insert(next);
                q.push({next,count + 1});
            }
        }
    }
    return -1;
}