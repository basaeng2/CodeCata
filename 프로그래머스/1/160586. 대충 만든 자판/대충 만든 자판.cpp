#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> first_press;

    for (string key : keymap)
    {
        int count = 0;
        for (char ch : key)
        {
            count++;
            if (first_press.find(ch) == first_press.end())
            {
                first_press[ch] = count;
            }
            else
            {
                first_press[ch] = min(first_press[ch], count);
            }
        }
    }

    for (string target : targets)
    {
        int total_press = 0;
        bool possible = true;

        for (char ch : target)
        {
            if (first_press.find(ch) == first_press.end())
            {
                possible = false;
                break;
            }
            total_press += first_press[ch];
        }

        if (possible)
            answer.push_back(total_press);
        else
            answer.push_back(-1);
    }
    return answer;
}