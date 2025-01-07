#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    while (!s.empty())
    {
        int count0 = 0;
        int count1 = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[0] == s[i]) count0++;
            else count1++;

            if (count0 == count1)
            {
                s = s.substr(count0 + count1, s.length() - 1);
                break;
            }
        }

        if (count0 != count1 && s.length() >= 1)
        {
            s = "";
        }
        answer++;
    }

    return answer;
}