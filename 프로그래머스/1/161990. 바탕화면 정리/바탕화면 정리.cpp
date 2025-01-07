#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<pair<int,int>> index;
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        if(wallpaper[i][j] == '#')
            index.push_back(make_pair(i,j));
    }
    
    int lux = INT_MAX;
    int luy = INT_MAX;
    int rdx = INT_MIN;
    int rdy = INT_MIN;
    
    for(int i = 0; i < index.size(); i++)
    {
        if(lux > index[i].first) lux = index[i].first;
        if(rdx < index[i].first) rdx = index[i].first;
        if(luy > index[i].second) luy = index[i].second;
        if(rdy < index[i].second) rdy = index[i].second;
    }   
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx + 1);
    answer.push_back(rdy + 1);
    
    return answer;
}