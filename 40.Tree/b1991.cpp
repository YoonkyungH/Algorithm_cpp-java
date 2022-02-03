// 트리 순회
// 전위 순회, 중위 순회, 후위 순회

// 전위: 현 - 왼 - 오
// 중위: 왼 - 현 - 오
// 후위: 왼 - 오 - 현

#include <iostream>

using namespace std;

struct Node {
    char left, right;
};

Node tree[27];
int N;
char a, b, c;

void preorder(char node) {   // 전위
    if(node == '.') return;

    cout << node;
    preorder(tree[node - 'A'].left);
    preorder(tree[node - 'A'].right);
}

void inorder(char node) { // 중위
    if(node == '.') return;

    inorder(tree[node - 'A'].left);
    cout << node;
    inorder(tree[node - 'A'].right);
}

void postorder(char node) {  // 후위
    if(node == '.') return;

    postorder(tree[node - 'A'].left);
    postorder(tree[node - 'A'].right);
    cout << node;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> a >> b >> c;

        tree[a-'A'].left = b;
        tree[a-'A'].right = c;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}