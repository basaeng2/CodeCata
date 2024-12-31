#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int min = INT_MAX;
    sort(score.rbegin(),  score.rend());
    
    for(int i = 0; i + m <= score.size(); i+=m)
    {
        min = score[i + m - 1];
        answer += min *  m;
    }
    return answer;
}