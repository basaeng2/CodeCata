#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, H;
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

vector<vector<vector<int>>> arr;
queue<pair<int, pair<int, int>>> q;

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().second.second;
        int y = q.front().second.first;
        int z = q.front().first;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H && arr[nz][ny][nx] == 0)
            {
                arr[nz][ny][nx] = arr[z][y][x] + 1;
                q.push({ nz, {ny, nx} });
            }
        }
    }
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[k][i][j] == 0)
                {
                    cout << -1;
                    return;
                }
            }
        }
    }
    int day = 0;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[k][i][j] > day)
                {
                    day = arr[k][i][j];                    
                }
            }
        }
    }
    cout << day - 1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    arr.resize(H, vector<vector<int>>(N, vector<int>(M)));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                {
                    q.push({ i, {j, k} });
                }
            }
        }
    }
    BFS();
}