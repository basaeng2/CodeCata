#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    int answer = n;

    // 전선 하나씩 제거
    for (int skip = 0; skip < wires.size(); skip++)
    {

        vector<vector<int>> graph(n + 1);

        // skip 번째 전선 제외하고 그래프 구성
        for (int i = 0; i < wires.size(); i++)
        {
            if (i == skip) continue;

            int a = wires[i][0];
            int b = wires[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // BFS
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int cnt = 1;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                    cnt++;
                }
            }
        }

        int other = n - cnt;

        answer = min(answer, abs(cnt - other));
    }

    return answer;
}