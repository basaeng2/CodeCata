#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirstword = true;

    for (char c : s) {
        if (c == ' ') {
            answer += c;
            isFirstword = true;
        } else if (isFirstword) {
            answer += (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
            isFirstword = false;
        } else {
            answer += (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
        }
    }

    return answer;
}
