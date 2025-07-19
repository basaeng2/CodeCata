#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> dq;

    for (const string& operation : operations) {
        stringstream ss(operation);
        char cmd;
        int number;
        ss >> cmd >> number;

        if (cmd == 'I')
        {
            dq.insert(number);
        }
        else if (cmd == 'D') 
        {
            if (!dq.empty())
            {
                if (number == 1)
                {
                    auto it = prev(dq.end());
                    dq.erase(it);
                }
                else if (number == -1)
                {
                    auto it = dq.begin();
                    dq.erase(it);
                }
            }
        }
    }

    if (dq.empty())
    {
        return {0, 0};
    }
    else
    {
        return {*prev(dq.end()), *dq.begin()};
    }
}
