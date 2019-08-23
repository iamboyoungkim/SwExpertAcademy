#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    for (int test = 0; test<10; test++) {
        int t, cnt, idx;
        string tofind, s;
        cin >> t >> tofind >> s;

        cnt = 0;
        idx = 0;
        for (int i = idx ;i<s.size(); i++) {
            int sSize = s.size();
            int fSize = tofind.size();
            if (s.substr(i, sSize).find(tofind) == 1) {
                cnt++;
                idx += fSize;
            }
            else idx += 1;
        }
        cout << "#" << t << " " << cnt << endl;
    }
}