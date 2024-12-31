#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> num_patterns = {
        {1, 2, 3, 4, 5},  // 수포자 1
        {2, 1, 2, 3, 2, 4, 2, 5},  // 수포자 2
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}  // 수포자 3
    };
    
    vector<int> scores(3, 0);
    
    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (answers[i] == num_patterns[j][i % num_patterns[j].size()]) {
                scores[j]++;
            }
        }
    }
    
    int maxScore = *max_element(scores.begin(), scores.end());
    
    for (int i = 0; i < 3; i++) {
        if (scores[i] == maxScore) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}