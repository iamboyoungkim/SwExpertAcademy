#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

int topni[5][9]; // 톱니바퀴의 정보
bool isVisit[5] = { false, }; // 이미 방문한 톱니인지?

void rotateTopni(int idx, int dir) {
    isVisit[idx] = true;

    int tmp1 = topni[idx][2];
    int tmp2 = topni[idx][6];

    // 시계방향
    if (dir == 1) {
        int tmp = topni[idx][7];
        for (int i = 6; i>=0; i--) {
            topni[idx][i+1] = topni[idx][i];
        }
        topni[idx][0] = tmp;
    }
    // 반시계방향
    else if (dir == -1) {
        int tmp = topni[idx][0];
        for (int i = 1; i<=7; i++) {
            topni[idx][i-1] = topni[idx][i];
        }
        topni[idx][7] = tmp;
    }
    // 양옆과 방향이 다른 경우 회전
    if (tmp1 != topni[idx+1][6] && idx+1 <= 4 && !isVisit[idx+1]) {
        rotateTopni(idx+1, dir*(-1));
    }
    if (tmp2 != topni[idx-1][2] && idx-1 >= 1 && !isVisit[idx-1]) {
        rotateTopni(idx-1, dir*(-1));
    }
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case) {
        int K;
        cin >> K;
        vector<pair<int, int>> rotateVec; // 회전 정보 (번호, 방향)

        for (int i = 1; i<=4; i++) {
            for (int j = 0; j<8; j++) {
                cin >> topni[i][j];
            }
        }

        for (int i = 0; i<K; i++) {
            int a, b;
            cin >> a >> b;
            rotateVec.push_back({a, b});
        }

        for (int i = 0; i<K; i++) {
            memset(isVisit, false, sizeof(isVisit));
            rotateTopni(rotateVec[i].first, rotateVec[i].second);
        }

        int res = 0;
        res = topni[1][0] + topni[2][0] * 2 + topni[3][0] * 4 + topni[4][0] * 8;
        printf("#%d %d\n", test_case, res);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}