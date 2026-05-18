#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    // 상 하 좌 우
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;

    q.push({0, 0});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            // 벽이면 이동 불가
            if (maps[nx][ny] == 0)
                continue;

            // 처음 방문한 경우
            if (maps[nx][ny] == 1)
            {
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 도착 못한 경우
    if (maps[n - 1][m - 1] == 1)
        return -1;

    return maps[n - 1][m - 1];
}