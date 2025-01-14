#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    // 내림차순 정렬
    sort(citations.rbegin(), citations.rend());
    
    // H-Index 계산
    int h_index = 0; // H-Index 초기화
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] >= i + 1) {
            h_index = i + 1; // 조건을 만족하면 h_index를 갱신
        } else {
            break; // 조건을 만족하지 않으면 반복 종료
        }
    }
    
    return h_index;
}
