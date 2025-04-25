#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    vector<int> weights = {781, 156, 31, 6, 1};
    
    unordered_map<char, int> vowelIndex = {
        {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}
    };
    
    for(int i = 0; i < word.length(); i++) {
        int idx = vowelIndex[word[i]];
        
        answer += idx * weights[i] + 1;
    }
    
    return answer;
}