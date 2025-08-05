#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void DFS(string current, string remaining, set<int>& numberSet)
{
    if(!current.empty())
    {
        numberSet.insert(stoi(current));
    }
    
    for(int i = 0; i < remaining.size(); i++)
    {
        string nextCurrent = current + remaining[i];
        string nextRemaining = remaining.substr(0, i) + remaining.substr(i + 1);
        DFS(nextCurrent, nextRemaining, numberSet);
    }
}

int solution(string numbers) {
    set<int> numberSet;    
    int answer = 0;
    
    DFS("", numbers, numberSet);
    
    for(int num : numberSet)
    {
        if(isPrime(num))
        {
            answer++;
        }
    }
    
    return answer;
}