#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), 0));
    int rows = arr1.size();          // 행의 개수
    int cols = arr1[0].size();       // 열의 개수
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}