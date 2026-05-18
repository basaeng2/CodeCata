#include <string>
#include <vector>
#include <queue>

using namespace std;

// 상, 하, 좌, 우 이동을 위한 방향 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 최대 좌표 50을 2배 확대하면 100이 되므로, 인덱스 100까지 쓸 수 있는 101x101 크기로 선언
    vector<vector<int>> board(101, vector<int>(101, 0));
    vector<vector<int>> visited(101, vector<int>(101, 0));

    // 1. 모든 직사각형의 테두리와 내부를 1로 채우기 (2배 확대)
    for (const auto& r : rectangle) {
        int x1 = r[0] * 2, y1 = r[1] * 2;
        int x2 = r[2] * 2, y2 = r[3] * 2;

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                board[i][j] = 1; 
            }
        }
    }

    // 2. 직사각형의 순수 내부만 다시 0으로 파내기 (가장 바깥 테두리만 1로 남김)
    for (const auto& r : rectangle) {
        int x1 = r[0] * 2, y1 = r[1] * 2;
        int x2 = r[2] * 2, y2 = r[3] * 2;

        for (int i = x1 + 1; i < x2; i++) {
            for (int j = y1 + 1; j < y2; j++) {
                board[i][j] = 0; 
            }
        }
    }

    // 3. BFS 최단 거리 탐색 설정
    queue<pair<int, int>> q;
    
    int startX = characterX * 2;
    int startY = characterY * 2;
    int targetX = itemX * 2;
    int targetY = itemY * 2;

    q.push({startX, startY});
    visited[startX][startY] = 1; // 시작 지점 방문 처리 (이동 거리 계산용)

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 아이템 위치에 도달했다면 거리 반환
        if (x == targetX && y == targetY) {
            // 시작할 때 1로 시작했으므로 1을 빼고, 2배 확대된 거리이므로 2로 나눔
            return (visited[x][y] - 1) / 2;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 101 && ny >= 0 && ny < 101) {
                // 오직 테두리(1) 위만 지나갈 수 있고, 아직 방문하지 않은 칸이어야 함
                if (board[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return 0;
}