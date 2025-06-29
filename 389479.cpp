#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int n = players.size();
    
    vector<int> addedServers(n, 0);
    
    for (int i = 0; i < n; i ++) {
        int neededServerAmount = players[i] / m;
        int addingServerAmount = neededServerAmount - addedServers[i];
        if(addingServerAmount <= 0) continue;
        answer += addingServerAmount;
        for(int j = i; j < i + k; j ++) {
            if(j >= n) break;
            addedServers[j] += addingServerAmount;
        }
    
    }
    return answer;
}
