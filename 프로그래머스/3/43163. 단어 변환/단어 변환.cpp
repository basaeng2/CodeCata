#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isOneDifference(const string& a, const string& b)
{
    int count = 0;
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != b[i]) count++;
        if(count > 1) return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
   if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    
    unordered_set<string> visited;
    visited.insert(begin);
    
    while(!q.empty())
    {
        string currentWord = q.front().first;
        int currentStep = q.front().second;
        q.pop();
        
        for(const string& word : words)
        {
            if(visited.find(word) == visited.end() && isOneDifference(currentWord, word))
            {
                if(word == target)
                {
                    answer = currentStep + 1;
                    return answer;
                }
                q.push(make_pair(word, currentStep + 1));
                visited.insert(word);
            }
        }
    }
    return 0;
}