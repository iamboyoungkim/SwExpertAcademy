#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <cstdlib> // for malloc
#include <cstring>

using namespace std;

struct Node {
    char ch;
    int left, right;
};

Node *nodes;

void printNodes(int vertex) {
    if (nodes[vertex].left != -1) printNodes(nodes[vertex].left - 1);
    cout << nodes[vertex].ch;
    if (nodes[vertex].right != -1) printNodes(nodes[vertex].right - 1);
}

int main(){
    for (int test = 1; test<=10; test++) {
        int N;
        cin >> N;

        nodes = (Node*)malloc(sizeof(Node) * N);

        for (int i = 0; i<N; i++) {
            int num;
            cin >> num >> nodes[i].ch;

            if ((i+1)*2 < N) {
                cin >> nodes[i].left;
                cin >> nodes[i].right;
            }
            else if ((i+1)*2 == N) {
                cin >> nodes[i].left;
                nodes[i].right = -1;
            }
            else {
                nodes[i].left = -1;
                nodes[i].right = -1;
            }
        }

        cout << "#" << test << " ";
        printNodes(0);
        cout << "\n";

        // 초기화
        free(nodes);
    }
    return 0;
}
