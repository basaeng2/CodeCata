#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string leftSide;
    for(int i = 1; i < food.size(); i++)
    {
       int count = food[i] / 2;
        leftSide += string(count, 48 + i);        
    }
    string rightSide =leftSide;
    reverse(rightSide.begin(), rightSide.end());
    answer = leftSide + "0" + rightSide;
    return answer;
}