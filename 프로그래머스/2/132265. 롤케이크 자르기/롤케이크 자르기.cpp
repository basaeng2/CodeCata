#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> right;
    unordered_set<int> left;
    
    for(int i = 0; i < topping.size(); i++)
    {
        right[topping[i]]++;
    }
    
    for(int i = 0; i < topping.size(); i++)
    {
        left.insert(topping[i]);
        
        right[topping[i]]--;
        
        if(right[topping[i]] == 0)
        {
            right.erase(topping[i]);
        }
        
        if(left.size() == right.size())
        {
            answer++;
        }
    }
    
    return answer;
}