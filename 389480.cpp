#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int left_a = n;
    int left_b = m;
    
    vector<vector<bool>> dp(n, vector<bool>(m, false));
    dp[0][0] = true;
    
    int size = info.size();
    
    for (int i = 0; i < size; ++ i) {
        vector<vector<bool>> next_dp(n, vector<bool>(m, false));
        
        for(int a = 0; a < n; ++ a) {
            for(int b = 0; b < m; ++ b) {
                if(!dp[a][b]) continue;
                
                int new_a = a + info[i][0];
                if (new_a < n) {
                    next_dp[new_a][b] = true;
                }
                
                int new_b = b + info[i][1];
                if (new_b < m) {
                    next_dp[a][new_b] = true;
                }
            }
        }
        dp = next_dp;
    }
    
    int min_a = n;
    for(int a = 0; a < n; a ++) {
        for(int b = 0; b < m; b ++) {
            if(dp[a][b])
                min_a = min(min_a, a);
        }
    }
    
    return (min_a == n) ? -1 : min_a;
}
