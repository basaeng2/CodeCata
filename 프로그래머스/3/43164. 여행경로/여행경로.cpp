#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool dfs(string current, int ticket_count, map<string, vector<pair<string, bool>>>& graph, vector<string>& answer) {
    // 모든 항공권을 다 사용했다면 성공 (경로의 길이는 티켓 수 + 1)
    if (answer.size() == ticket_count + 1) {
        return true;
    }

    for (auto& next : graph[current]) {
        string next_airport = next.first;
        bool& is_used = next.second;

        if (is_used) continue;

        is_used = true;
        answer.push_back(next_airport);

        if (dfs(next_airport, ticket_count, graph, answer)) {
            return true;
        }
        
        is_used = false;
        answer.pop_back();
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());

    map<string, vector<pair<string, bool>>> graph;
    for (const auto& ticket : tickets) {
        graph[ticket[0]].push_back({ticket[1], false});
    }

    answer.push_back("ICN");

    dfs("ICN", tickets.size(), graph, answer);

    return answer;
}