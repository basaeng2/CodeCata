#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    
    for(int item : ingredient)
    {
        stack.push_back(item);
        
        if(stack.size() >= 4 &&
            stack[stack.size() - 4] == 1 &&
            stack[stack.size() - 3] == 2 &&
            stack[stack.size() - 2] == 3 &&
            stack[stack.size() - 1] == 1)
        {
            for(int i = 0; i < 4; i++)
            stack.pop_back();
            
            answer++;
        }
    }    
    return answer;
}
