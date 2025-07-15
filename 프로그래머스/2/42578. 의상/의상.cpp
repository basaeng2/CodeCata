#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> cloth;
    for(vector<string> c : clothes)
    {
        cloth[c[1]]++;
    }
    for(auto& it : cloth)
    {
        // +1은 그 종류의 옷을 "입지 않는 경우"를 의미
        answer *= it.second + 1;
    }
    
    return answer - 1;
}