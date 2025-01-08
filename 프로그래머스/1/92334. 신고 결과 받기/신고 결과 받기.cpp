#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, unordered_set<string>> report_map;
    unordered_map<string, int> user_index;
    
    for(int i = 0 ; i < id_list.size(); i++)
    {
        user_index[id_list[i]] = i;
    }
    
    for(const string& r : report)
    {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;
        
        report_map[reported].insert(reporter);
    }
    
    for(const auto& entry : report_map)
    {
        const string& reported = entry.first;
        const unordered_set<string>& reporters = entry.second;
        
        if(reporters.size() >= k)
        {
            for(const string& reporter : reporters)
            {
                answer[user_index[reporter]]++;
            }
        }        
    }
    return answer;
}