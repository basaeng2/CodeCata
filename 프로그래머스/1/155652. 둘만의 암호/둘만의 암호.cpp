#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> Alphabet;

    sort(skip.begin(), skip.end());
        
    for(int i = 0; i < 26; i ++)
    {
        char ch = 'a' + i;
        if(find(skip.begin(), skip.end(), ch) == skip.end())
         Alphabet.push_back(ch);
    }
    
    for(char ch : s)
    {
        int pos = find(Alphabet.begin(),Alphabet.end(), ch) - Alphabet.begin();
        pos = (pos + index) % Alphabet.size();
        answer += Alphabet[pos];
    }
    
    return answer;
}