#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int level = 0;
    int zeroCount = 0;

    while (s != "1") {
        int currentZeroCount = count(s.begin(), s.end(), '0');
        zeroCount += currentZeroCount;

        int lengthAfterRemoval = s.size() - currentZeroCount;

        s = "";
        while (lengthAfterRemoval > 0) {
            s += (lengthAfterRemoval % 2) ? '1' : '0';
            lengthAfterRemoval /= 2;
        }

        reverse(s.begin(), s.end());

        level++;
    }

    return {level, zeroCount};
}
