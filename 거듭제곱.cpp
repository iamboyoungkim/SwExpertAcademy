#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int go(int n1, int n2) {
    if (n2 < 2) return n1;
    return n1 * go(n1, n2-1);

}

int main() {
    for (int t = 0; t<10; t++) {
        int test, num1, num2;
        int res = 1;
        cin >> test >> num1 >> num2;

        res = go(num1, num2);

        cout << "#" << test << " " << res << endl;
    }
}