#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {

    vector<int> days_in_month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int total_days = 0;
    
    for (int i = 0; i < a - 1; i++) {
        total_days += days_in_month[i];
    }
    
    total_days += b;
    int weekday_index = (total_days + 4) % 7;  // 4는 1월 1일이 금요일이기 때문
    
    vector<string> weekdays = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    return weekdays[weekday_index];
}