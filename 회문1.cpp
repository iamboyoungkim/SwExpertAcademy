#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    for (int test = 1; test<=10; test++) {
        int n;
        char map[9][9];
        int res = 0;

        cin >> n;

        for (int i = 0; i<8; i++) {
            for (int j = 0; j<8; j++) {
                cin >> map[i][j];
            }
        }

        // 가로 확인
        for (int i = 0; i<8; i++) {
            for (int j = 0; j<=8-n ; j++) {
                bool flag = true;
                for (int k = 0; k<n/2; k++) {
                    if (map[i][j+k] != map[i][n+j-k-1]) flag = false;
                }
                if (flag) res++;
            }
        }

        // 세로 확인
        for (int i = 0; i<8; i++) {
            for (int j = 0; j<=8-n ; j++) {
                bool flag = true;
                for (int k = 0; k<n/2; k++) {
                    if (map[j+k][i] != map[n+j-k-1][i]) flag = false;
                }
                if (flag) res++;
            }
        }

        cout << "#" << test << " " << res << endl;
    }

}