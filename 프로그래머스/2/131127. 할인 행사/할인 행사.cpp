#include <string>
#include <vector>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    vector<pair<string, int>> Mine;
    
    for(int i = 0; i < want.size(); i++)
    {
        Mine.push_back(make_pair(want[i], number[i]));
    }
    
    int TotalDays = discount.size();
    int WindowSize = 10;
        
    for(int Start = 0; Start <= TotalDays - WindowSize; Start++)
    {
        vector<pair<string, int>> WindowCount = Mine;
        for(int i = Start; i < Start + WindowSize; i++)
        {
            for(auto& item : WindowCount)
            {
                if(item.first == discount[i])
                {
                    item.second--;
                    break;
                }
            }
        }
        
        bool Flag = true;
        for(const auto& item : WindowCount)
        {
            if(item.second > 0)
            {
                Flag = false;
                break;
            }
        }        
        if(Flag) answer++;
    }    
    return answer;
}