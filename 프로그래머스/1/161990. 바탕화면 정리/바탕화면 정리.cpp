#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int lux = INT_MAX;
    int luy = INT_MAX;
    int rdx = INT_MIN;
    int rdy = INT_MIN;
    
    vector<int> index = {lux, luy, rdx, rdy};
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        if(wallpaper[i][j] == '#')
        {
            lux = min(lux, i);
            luy = min(luy, j);
            rdx = max(rdx, i);
            rdy = max(rdy, j);
        }
    }
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx + 1);
    answer.push_back(rdy + 1);
    
    return answer;
}