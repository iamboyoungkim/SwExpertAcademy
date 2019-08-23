#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > v;
int res;

void go(int cur) {
    if (cur == 99) res = 1;

    for (int i = 0; i<v[cur].size(); i++) {
        go(v[cur][i]);
    }
}

int main() {
    for (int t = 1; t<=10; t++) {
        int test, num;
        cin >> test >> num;

        v.resize(num);

        for (int i = 0; i<num; i++) {
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
        }
        go(0);

        cout << "#" << test << " " << res << endl;

        v.clear();
        res = 0;
    }
    return 0;
}