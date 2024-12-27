#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string result = "";
    int index = 0; 

    for (char c : s) {
        if (c == ' ') { 
            result += c;
            index = 0;
        } else {
            if (index % 2 == 0) {
                result += toupper(c);
            } else {
                result += tolower(c);
            }
            index++;
        }
    }

    return result;
}
