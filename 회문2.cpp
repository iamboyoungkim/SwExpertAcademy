#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    for (int test = 1; test<=10; test++) {
        int t, n;
        char map[101][101];
        int res = -1;

        cin >> t;

        for (int i = 0; i<100; i++) {
            for (int j = 0; j<100; j++) {
                cin >> map[i][j];
            }
        }

        // 가로 확인
        for (int n = 1; n<=100; n++) {
            for (int i = 0; i<100; i++) {
                for (int j = 0; j<=100-n ; j++) {
                    bool flag = true;
                    for (int k = 0; k<n/2; k++) {
                        if (map[i][j+k] != map[i][n+j-k-1]) flag = false;
                    }
                    if (flag && res < n) res = n;
                }
            }
        }


        // 세로 확인
        for (int n = 1; n<=100; n++) {
            for (int i = 0; i<100; i++) {
                for (int j = 0; j<=100-n ; j++) {
                    bool flag = true;
                    for (int k = 0; k<n/2; k++) {
                        if (map[j+k][i] != map[n+j-k-1][i]) flag = false;
                    }
                    if (flag && res < n) res = n;
                }
            }
        }

        cout << "#" << t << " " << res << endl;
    }

}