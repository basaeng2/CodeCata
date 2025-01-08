#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width, height;
    int total = brown + yellow;
    
    for(height = 3; height <= total / 3; height++)
    {
        if(total % height == 0)
        {
            width = total / height;
            if((height - 2) * (width - 2) == yellow)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    
    return answer;
}