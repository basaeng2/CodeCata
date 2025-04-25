#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    
    map<string, int> entryTimes;
    map<string, int> totalParkingTime;
    
    for (const string& record : records) {
        string time = record.substr(0, 5);
        string carNumber = record.substr(6, 4);
        string action = record.substr(11);
        
        int currentTime = timeToMinutes(time);
        
        if (action == "IN")
        {
            entryTimes[carNumber] = currentTime;
        }
        else
        {
            int entryTime = entryTimes[carNumber];
            int parkingDuration = currentTime - entryTime;
        
            totalParkingTime[carNumber] += parkingDuration;
            
            entryTimes.erase(carNumber);
        }
    }
    
    int endOfDay = timeToMinutes("23:59");
    for (const auto& entry : entryTimes)
    {
        string carNumber = entry.first;
        int entryTime = entry.second;
        int parkingDuration = endOfDay - entryTime;
        
        totalParkingTime[carNumber] += parkingDuration;
    }
    
    vector<int> answer;
    for (const auto& entry : totalParkingTime)
    {
        string carNumber = entry.first;
        int totalTime = entry.second;
        int fee;
        
        if (totalTime <= basicTime)
        {
            fee = basicFee;
        }
        else
        {
            int extraTime = totalTime - basicTime;
            int extraUnits = (extraTime + unitTime - 1) / unitTime;
            int extraFee = extraUnits * unitFee;
            fee = basicFee + extraFee;
        }
        
        answer.push_back(fee);
    }
    
    return answer;
}