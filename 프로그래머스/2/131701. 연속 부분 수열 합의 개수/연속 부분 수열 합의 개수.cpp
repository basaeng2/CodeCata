#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> uniqueSums;
    int n = elements.size();
    
    vector<int> circular(elements.begin(), elements.end());
    circular.insert(circular.end(), elements.begin(), elements.end());
    
    for (int length = 1; length <= n; ++length) {
        for (int start = 0; start < n; ++start) {
            int sum = 0;
            for (int i = 0; i < length; ++i) {
                sum += circular[start + i];
            }
            uniqueSums.insert(sum);
        }
    }
    
    return uniqueSums.size();
}
