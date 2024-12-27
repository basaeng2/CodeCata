#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int l = p.length();
    long long p_num = stoll(p);

    for (int i = 0; i <= t.length() - l; i++) {
        string num_str = t.substr(i, l);
        long long num = stoll(num_str);
        
        if (num <= p_num) {
            answer++;
        }
    }

    return answer;
}
