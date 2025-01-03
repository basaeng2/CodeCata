#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int count = 0;
    vector<int> Divisors;
    for(int i = 1; i <= number; i++)
    {
        for(int j = 1; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                count++;
                if(j != i / j)
                {
                    count++;
                }
            }
        }
        Divisors.push_back(count);
        count = 0;
    }
    
    for(int i = 0; i < Divisors.size(); i++)
    {
        if(Divisors[i] <= limit)
            answer += Divisors[i];
        else
            answer += power;
    }
    
    return answer;
}