// 집합의 표현
// union_find (유니온 파인드 그 자체)

#include <iostream>

using namespace std;

// 배열은 대부분의 문제에서 백만까지가 맥시멈
int arr[1000001];   // 부모가 값으로 들어올 것

int find(int p) {    // 부모를 반환
    if(arr[p] == p) { return p; }
    return arr[p] = find(arr[p]);   // 경로 압축
}

void unionParent(int b, int c) {
    arr[find(b)] = find(c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<=n; i++) {    // 자기 자신으로 부모노드를 초기화 (n까지 포함하는거 잊지말기)
        arr[i] = i;
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a==0) {
            unionParent(b, c);
        } else {
            if(find(b) == find(c)) { cout << "YES\n"; }
            else { cout << "NO\n"; }
        }
    }

    return 0;
}