#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    int num;
    
    int max = INT_MIN;
    int min = INT_MAX;
    
    for(int i = 0; i < s.size(); i++)
    {
        ss >> num;
        if(max < num) max = num;
        if(min > num) min = num;
    }
    answer = to_string(min) + " " + to_string(max);
    
    
    return answer;
}