#include <string>
#include <vector>

using namespace std;

void DFS(int node, vector<vector<int>>& computers, vector<bool>& visited)
{
    visited[node] = true;
    for(int i = 0; i< computers.size(); i++)
    {
        if(computers[node][i] == 1 && !visited[i])
        {
            DFS(i, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            DFS(i, computers, visited);
            answer++;
        }
    }
    
    return answer;
}