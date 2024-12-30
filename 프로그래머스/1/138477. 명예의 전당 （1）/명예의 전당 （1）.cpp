#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honor;

    for (int i = 0; i < score.size(); i++) {
        honor.push_back(score[i]);
        sort(honor.rbegin(), honor.rend());
        
        if (honor.size() > k) {
            honor.pop_back();
        }
        answer.push_back(honor.back());
    }    
    return answer;
}
