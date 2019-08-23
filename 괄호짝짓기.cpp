#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
    for (int t = 1; t<=10; t++) {
        int res = 0, len;
        string str;

        cin >> len;
        cin >> str;

        stack<char> st;

        for (int i = 0; i<len; i++) {
            // 여는 괄호
            if (str[i] == '(' || str[i] == '{' || str[i] == '<' || str[i] == '[') st.push(str[i]);
            // 닫는 괄호 + 짝 맞음
            else if (str[i] == ')' && st.top() == '(') st.pop();
            else if (str[i] == '}' && st.top() == '{') st.pop();
            else if (str[i] == '>' && st.top() == '<') st.pop();
            else if (str[i] == ']' && st.top() == '[') st.pop();
            // 둘다 아닐 경우
            else st.push(str[i]);
        }
        // 비어있지 않으면 잘 맞은 것
        if (st.empty()) res = 1;

        cout << "#" << t << " " << res << endl;
    }
}