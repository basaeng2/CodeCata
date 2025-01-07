#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> playerRank;

    for (int i = 0; i < players.size(); i++)
    {
        playerRank[players[i]] = i;
    }
    
    for (const string& calling : callings)
    {
        int currentRank = playerRank[calling];

        if (currentRank > 0)
        {
            int previousRank = currentRank - 1;

            string previousPlayer = players[previousRank];
            swap(players[currentRank], players[previousRank]);

            playerRank[calling] = previousRank;
            playerRank[previousPlayer] = currentRank;
        }
    }

    return players;
}
