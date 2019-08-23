#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T, N, X; // 테스트케이스, 맵크기, 경사로길이
    int res; //정답
    cin >> T;

    int map[21][21];

    for(test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> X;

        for (int i = 0; i<N; i++) {
            for (int j = 0; j<N; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i<N; i++) {
            // 행 확인
            int cnt = 1; // 높이 같은 경우 카운
            for (int j = 1; j<N; j++) {
                int prev = map[i][j-1];
                int cur = map[i][j];

                if (prev == cur) {
                    cnt++;
                }

                // 내려가는 경사로 -> 앞으로 X만큼
                else if (prev - cur == 1 && cnt >= 0) {
                    cnt = 1 - X;
                }

                // 올라가는 경사로 -> 이미 X만큼 있음
                else if (prev - cur == -1 && cnt >= X) {
                    cnt = 1;
                }

                // 경사로 건설 불가능
                else {
                    cnt = -1;
                    break;
                }
            }
            if (cnt >= 0) res++;

            // 열 확인
            cnt = 1;
            for (int j = 1; j<N; j++) {
                int prev = map[j-1][i];
                int cur = map[j][i];

                if (prev == cur) {
                    cnt++;
                }

                    // 내려가는 경사로 -> 앞으로 X만큼
                else if (prev - cur == 1 && cnt >= 0) {
                    cnt = 1 - X;
                }

                    // 올라가는 경사로 -> 이미 X만큼 있음
                else if (prev - cur == -1 && cnt >= X) {
                    cnt = 1;
                }

                    // 경사로 건설 불가능
                else {
                    cnt = -1;
                    break;
                }
            }
            if (cnt >= 0) res++;
        }

        printf("#%d %d\n", test_case, res);
        res = 0;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
