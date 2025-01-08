#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    map<int, int> size_map;
    for (int size : tangerine) {
        size_map[size]++;
    }

    vector<int> counts;
    for (auto &[size, count] : size_map) {
        counts.push_back(count);
    }
    
    sort(counts.rbegin(), counts.rend());
    
    int selected = 0;
    for (int count : counts) {
        selected += count;
        answer++;
        if (selected >= k) {
            break;
        }
    }

    return answer;
}