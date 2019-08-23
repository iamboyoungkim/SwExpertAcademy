#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
    for (int test = 1; test<=10; test++) {
        int N, orderN;
        cin >> N;

        list<int> numList; // 숫자 저장할 배열

        // 원본 암호문 입력
        for (int i = 0; i<N; i++) {
            int num;
            cin >> num;
            numList.push_back(num);
        }

        cin >> orderN;
        for (int i = 0; i<orderN; i++) {
            char ord; // 명령 번호
            cin >> ord;

            if (ord == 'I') {
                int pos, cnt;
                cin >> pos >> cnt;
                list<int> tmpList;

                for (int j = 0; j<cnt; j++) {
                    int tmp;
                    cin >> tmp;
                    tmpList.push_back(tmp);
                }

                list<int> ::iterator iter;
                iter = numList.begin();
                while (pos > 0) { // 위치 찾기
                    iter++;
                    pos--;
                }
                numList.splice(iter, tmpList);
            }

            else if (ord == 'D') {
                int pos, cnt;
                cin >> pos >> cnt;

                list<int> ::iterator iter;
                iter = numList.begin();
                while (pos > 0) { // 위치 찾기
                    iter++;
                    pos--;
                }

                for (int k = 0; k<cnt; k++) {
                    numList.erase(iter++);
                }
            }
            else if (ord == 'A') {
                int cnt;
                cin >> cnt;

                for (int k = 0; k<cnt; k++) {
                    int num;
                    cin >> num;
                    numList.push_back(num);
                }
            }
        }

        cout << "#" << test << " ";
        for (int x = 0; x<10; x++) {
            cout << numList.front() << " ";
            numList.pop_front();
        }
        cout << endl;
        numList.clear();
    }

    return 0;
}