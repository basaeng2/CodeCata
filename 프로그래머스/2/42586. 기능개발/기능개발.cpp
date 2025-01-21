#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        int remaining = 100 - progresses[i];
        int day = ceil((double)remaining / speeds[i]);
        days.push_back(day);
    }
    
    int current_day = days[0];
    int count = 1;
    
    for(int i = 1; i < days.size(); i++)
    {
        if(days[i] <= current_day)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            count = 1;
            current_day = days[i];
        }
    }
    answer.push_back(count);
    
    return answer;
}