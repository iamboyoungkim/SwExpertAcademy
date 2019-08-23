#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> num;
stack<pair<int, char> > op;

void calculate() {
    int res;
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    char c = op.top().second;
    op.pop();

    if (c == '*') res = a * b;
    else if (c == '/') res = a / b;
    else if (c == '+') res = a + b;
    else if (c == '-') res = a - b;

    num.push(res);
}

int main() {
    for (int test = 1; test<=10; test++) {
        int N;
        string str;

        cin >> N;
        cin >> str;

        for (int i = 0; i<N; i++) {
            // 여는 괄호일 경우
            // 우선순위 가장 낮음
            if (str[i] == '(') {
                op.push({0, str[i]});
            }
            // 닫는 괄호일 경우
            // 여는 괄호 나올때까지 계산
            else if (str[i] == ')') {
                while(op.top().second != '(') {
                    calculate();
                }
                op.pop();

            }
            // 연산자일 경우
            else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
                int priority;
                if (str[i] == '*' || str[i] == '/') {
                    priority = 2;
                }
                else if (str[i] == '+' || str[i] == '-') {
                    priority = 1;
                }
                // 우선순위 낮은게 top으로 올때까지
                while(!op.empty() && op.top().first >= priority) {
                    calculate();
                }
                op.push({priority, str[i]});
            }
            // 숫자일 경우
            else {
                num.push(str[i] - '0');
            }
        }

        while (!op.empty()) calculate();
        cout << "#" << test << " " << num.top() << endl;
    }

}