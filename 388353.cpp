#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool can_pull(const vector<string>& storage, int si, int sj) {
    int H = storage.size(), W = storage[0].size();
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int,int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        if (x == 0 || y == 0 || x == H-1 || y == W-1) return true;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && storage[nx][ny] == ' ') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    int H = storage.size(), W = storage[0].size();
    int answer = H * W;
    vector<vector<char>> board(H, vector<char>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            board[i][j] = storage[i][j];

    for (int r = 0; r < requests.size(); ++r) {
        string req = requests[r];
        char type = req[0];
        bool changed = false;

        if (req.length() == 1) {
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < W; ++j) {
                    if (board[i][j] == type && can_pull(storage, i, j)) {
                        board[i][j] = ' ';
                        answer--;
                        changed = true;
                    }
                }
            }
        } else {
            for (int i = 0; i < H; ++i)
                for (int j = 0; j < W; ++j)
                    if (board[i][j] == type) {
                        board[i][j] = ' ';
                        answer--;
                        changed = true;
                    }
        }
        for (int i = 0; i < H; ++i) {
            storage[i] = string(board[i].begin(), board[i].end());
        }
    }
    return answer;
}
