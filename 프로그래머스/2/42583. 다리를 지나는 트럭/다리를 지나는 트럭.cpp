#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge; // (트럭 무게, 진입 시간)
    int time = 0;
    int total_weight = 0;
    int idx = 0;

    while (idx < truck_weights.size() || !bridge.empty()) {
        time++;

        // 다리를 가장 먼저 올라간 트럭이 다리를 다 건넜는지
        // time - bridge.front().second >= bridge_length
        if (!bridge.empty() && time - bridge.front().second >= bridge_length) {
            total_weight -= bridge.front().first;
            bridge.pop();
        }

        if (idx < truck_weights.size() && total_weight + truck_weights[idx] <= weight) {
            bridge.push({truck_weights[idx], time});
            total_weight += truck_weights[idx];
            idx++;
        }
    }

    return time;
}
