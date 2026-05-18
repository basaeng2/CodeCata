#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

vector<pair<int, int>> normalize(vector<pair<int, int>> points)
{
    int min_r = 1e9, min_c = 1e9;
    for (auto& p : points)
    {
        min_r = min(min_r, p.first);
        min_c = min(min_c, p.second);
    }
    
    // 최소값을 빼서 (0,0) 기반으로 이동
    for (auto& p : points)
    {
        p.first -= min_r;
        p.second -= min_c;
    }
    
    sort(points.begin(), points.end());
    return points;
}

vector<pair<int, int>> rotate(const vector<pair<int, int>>& points)
{
    vector<pair<int, int>> rotated;
    for (auto& p : points)
    {
        // (r, c) -> (c, -r) 공식
        rotated.push_back({p.second, -p.first});
    }
    return normalize(rotated);
}

vector<vector<pair<int, int>>> extract_shapes(vector<vector<int>>& grid, int target_value)
{
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<pair<int, int>>> shapes;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == target_value && !visited[i][j])
            {
                vector<pair<int, int>> shape;
                queue<pair<int, int>> q;
                
                q.push({i, j});
                visited[i][j] = true;
                
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    shape.push_back({r, c});
                    
                    for (int d = 0; d < 4; ++d)
                    {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n)
                        {
                            if (grid[nr][nc] == target_value && !visited[nr][nc])
                            {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
                shapes.push_back(normalize(shape));
            }
        }
    }
    return shapes;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;

    // 보드에서는 빈칸(0) 추출, 테이블에서는 퍼즐조각(1) 추출
    vector<vector<pair<int, int>>> spaces = extract_shapes(game_board, 0);
    vector<vector<pair<int, int>>> pieces = extract_shapes(table, 1);
    
    // 퍼즐 조각 사용 여부 체크 배열
    vector<bool> piece_used(pieces.size(), false);

    // 모든 빈 공간에 대해 매칭 시도
    for (const auto& space : spaces)
    {
        bool matched = false;
        
        for (size_t i = 0; i < pieces.size(); ++i)
        {
            if (piece_used[i]) continue; // 이미 사용한 조각 패스
            if (space.size() != pieces[i].size()) continue; // 크기가 다르면 패스

            vector<pair<int, int>> curr_piece = pieces[i];
            
            // 0도, 90도, 180도, 270도 회전하며 매칭 확인
            for (int r = 0; r < 4; ++r)
            {
                if (space == curr_piece)
                {
                    piece_used[i] = true;
                    answer += space.size(); // 채워진 칸 수 누적
                    matched = true;
                    break;
                }
                curr_piece = rotate(curr_piece); // 90도 회전
            }
            
            if (matched) break; // 빈 공간 하나에 조각을 찾았으므로 다음 공간으로
        }
    }

    return answer;
}
//.