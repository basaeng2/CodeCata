#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int height = park.size();
    int width = park[0].size();
    int start_row = 0, start_col = 0;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (park[i][j] == 'S')
            {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    char dir_map[4] = {'E', 'W', 'S', 'N'};

    for (const string& route : routes)
    {
        char op = route[0];
        int dist = stoi(route.substr(2));
        int dir_idx = 0;

        for (int i = 0; i < 4; ++i)
        {
            if (dir_map[i] == op)
            {
                dir_idx = i;
                break;
            }
        }

        int d_row = directions[dir_idx].first;
        int d_col = directions[dir_idx].second;

        int new_row = start_row, new_col = start_col;
        bool valid = true;
        for (int step = 1; step <= dist; ++step)
        {
            new_row += d_row;
            new_col += d_col;

            if (new_row < 0 || new_row >= height || new_col < 0 || new_col >= width || park[new_row][new_col] == 'X')
            {
                valid = false;
                break;
            }
        }
        
        if (valid)
        {
            start_row = new_row;
            start_col = new_col;
        }
    }

    return {start_row, start_col};
}
