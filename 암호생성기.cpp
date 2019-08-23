#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main(){
    for (int i = 1; i<=10; i++) {
        int test, num;
        queue<int> q;

        cin >> test;
        for (int j = 0; j<8; j++) {
            cin >> num;
            q.push(num);
        }

        int idx = 1;
        while(true) {
            int tmp = q.front();
            tmp -= idx;
            q.pop();
            if (tmp <= 0) {
                q.push(0);
                break;
            }
            else q.push(tmp);
            idx++;

            if (idx >= 6) idx = 1;
        }

        string str;
        for (int i = 0; i<8; i++) {
            int tmp = q.front();
            q.pop();
            str += to_string(tmp);
            str += " ";
        }

        cout << "#" << test << " " << str << endl;
    }
    return 0;
}