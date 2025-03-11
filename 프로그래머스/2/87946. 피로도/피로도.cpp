#include <vector>
#include <algorithm>

using namespace std;

int maxDungeons = 0;

void explore(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count)
{
    maxDungeons = max(maxDungeons, count);

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && k >= dungeons[i][0])
        {
            visited[i] = true;
            explore(k - dungeons[i][1], dungeons, visited, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons){
    vector<bool> visited(dungeons.size(), false);
    maxDungeons = 0;
    explore(k, dungeons, visited, 0);
    return maxDungeons;
}
