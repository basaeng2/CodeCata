#include <string>
#include <vector>
#include <cmath>

using namespace std;

string convertToBase(int n, int k) {
    if (n == 0) return "0";
    
    string result = "";
    while (n > 0)
    {
        result = to_string(n % k) + result;
        n /= k;
    }
    return result;
}

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    long long limit = sqrt(n);
    for (long long i = 3; i <= limit; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    string converted = convertToBase(n, k);
    
    int count = 0;
    string current = "";
    
    for (char c : converted)
    {
        if (c == '0')
        {
            if (!current.empty() && isPrime(stoll(current)))
            {
                count++;
            }
            current = "";
        }
        else
        {
            current += c;
        }
    }
    if (!current.empty() && isPrime(stoll(current)))
    {
        count++;
    }
    
    return count;
}