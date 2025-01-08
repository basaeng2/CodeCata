#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while(a != b)
    {
        answer ++;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        if(a==b)
            answer--;        
    }

    return answer;
}