#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < reserve.size(); i++) {
        auto it = find(lost.begin(), lost.end(), reserve[i]);
        if (it != lost.end()) {
            lost.erase(it);
            reserve[i] = -1;
        }
    }

    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] == -1) continue;
        
        if (find(lost.begin(), lost.end(), reserve[i] - 1) != lost.end()) {
            lost.erase(find(lost.begin(), lost.end(), reserve[i] - 1));
        } else if (find(lost.begin(), lost.end(), reserve[i] + 1) != lost.end()) {
            lost.erase(find(lost.begin(), lost.end(), reserve[i] + 1));
        }
    }

    return n - lost.size();
}
