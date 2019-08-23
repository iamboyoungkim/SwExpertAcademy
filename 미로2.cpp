#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Dir {
    int y, x;
};

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int map[102][102];
bool isVisit[102][102];
bool flag = false;

void dfs(int startX, int startY) {
    isVisit[startY][startX] = true;

    for (int i = 0; i<4; i++) {
        int nextX = startX + moveDir[i].x;
        int nextY = startY + moveDir[i].y;

        if (map[nextY][nextX] == 3) flag = true;
        else if (!isVisit[nextY][nextX] && map[nextY][nextX] == 0 && !flag)
            dfs(nextX, nextY);
    }
}
int main(){
    for (int i = 0; i<10; i++) {
        int test;
        cin >> test;

        string str;
        int startX, startY;

        for (int i = 1; i<=100; i++) {
            cin >> str;
            for (int j = 1; j<=100; j++) {
                map[i][j] = str[j-1] - '0';
                if (map[i][j] == 2) {
                    startX = j;
                    startY = i;
                }
            }
        }

        dfs(startX, startY);

        if (flag) cout << "#" << test << " 1" << endl;
        else cout << "#" << test << " 0" << endl;

        flag = false;
        memset(map, -1, sizeof(map));
        memset(isVisit, false, sizeof(isVisit));
    }

    return 0;
}