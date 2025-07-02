#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    const int h = maps.size();
    const int w = maps[0].length();
    vector< vector <bool> > visited(h, vector<bool>(w, false));
    bool isIslandExist = false;
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if(maps[i][j] != 'X') isIslandExist = true;
        }
    }
    if(!isIslandExist) {
        answer.push_back(-1);
        return answer;
    }
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if(visited[i][j] || maps[i][j] == 'X') continue;
            int foods = maps[i][j] - '0';
            queue<pair<int, int> > islands;
            if(i > 0) {
                pair<int, int> is(i - 1, j);
                islands.push(is);
            }
            if(j > 0) {
                pair<int, int> is(i, j - 1);
                islands.push(is);
            }
            if(i < h - 1) {
                pair<int, int> is(i + 1, j);
                islands.push(is);
            }
            if(j < w - 1) {
                pair<int, int> is(i, j + 1);
                islands.push(is);
            }
            while(!islands.empty()) {
                int x = islands.front().first;
                int y = islands.front().second;
                islands.pop();
                if(visited[x][y] || maps[x][y] == 'X' || (x == i && y == j)) continue;
                foods += maps[x][y] - '0';
                visited[x][y] = true;
                if(x > 0) {
                pair<int, int> is(x - 1, y);
                islands.push(is);
            }
            if(y > 0) {
                pair<int, int> is(x, y - 1);
                islands.push(is);
            }
            if(x < h - 1) {
                pair<int, int> is(x + 1, y);
                islands.push(is);
            }
            if(y < w - 1) {
                pair<int, int> is(x, y + 1);
                islands.push(is);
            }
            }
            answer.push_back(foods);
            visited[i][j] = true;
        }
    }
    int l = answer.size();
    sort(&answer[0], &answer[l]);
    for (int i = 0; i < l; i ++) {
        cout << answer[i] << " ";
    }cout << endl;
    return answer;
}

int main(void) {
    vector<string> maps;
    maps.push_back("X591X");
    maps.push_back("X1X5X");
    maps.push_back("X231X");
    maps.push_back("1XXX1");
    solution(maps);
    return 1;
}