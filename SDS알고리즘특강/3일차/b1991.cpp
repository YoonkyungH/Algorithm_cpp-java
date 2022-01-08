// 트리 순회
// 전위순회, 중위순회, 후위순회

#include <iostream>

using namespace std;

struct stNode {
    char left, right;
};

stNode tree[27];

void preOrder(char node) {  // 전위 순회(루트 -> 왼쪽 -> 오른쪽)
    if(node == '.') return;

    cout << node;   // 전위순회는 일단 그 자리 출력
    preOrder(tree[node-'A'].left);
    preOrder(tree[node-'A'].right);
}

void inOrder(char node) {   // 중위 순회(왼쪽 -> 루트 -> 오른쪽)
    if(node == '.') return;

    inOrder(tree[node-'A'].left);
    cout << node;
    inOrder(tree[node - 'A'].right);
}

void postOrder(char node) { // 후위 순회(왼쪽 -> 오른쪽 -> 루트)
    if(node == '.') return;

    postOrder(tree[node-'A'].left);
    postOrder(tree[node-'A'].right);
    cout << node;
}

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        tree[a-'A'].left = b;   // a-'A': a가 'A'라면 'A'-'A' = 1 (즉, A는 1, B는 2 ...)
        tree[a-'A'].right = c;

        cout << "TEST: " << a-'A' << '\n';
    }

    preOrder('A');
    cout << '\n';

    inOrder('A');
    cout << '\n';

    postOrder('A');
    cout << '\n';

    return 0;
}