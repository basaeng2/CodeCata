#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int i = 0, j = 0;
    for (const string& word : goal) {      
        if (i < cards1.size() && cards1[i] == word) {
            i++;
        }
        else if (j < cards2.size() && cards2[j] == word) {
            j++;
        }
        else {
            answer = "No";
            return answer;
        }
    }
    answer = "Yes";
    return answer;
}