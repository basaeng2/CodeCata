#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getRank(int match)
{
    if(match >= 2)
    {
        return 7 - match;
    }
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_set<int> win_nums_set(win_nums.begin(), win_nums.end());
    
    int count = 0;
    int match = 0;
    
    for(int num : lottos)
    {
        if(num == 0)
            count ++;
        else if(win_nums_set.find(num) != win_nums_set.end())
            match++;
    }
    
    int maxRank = getRank(match + count);
    int minRank = getRank(match);
    
    answer.push_back(maxRank);
    answer.push_back(minRank);
    
    return answer;
}