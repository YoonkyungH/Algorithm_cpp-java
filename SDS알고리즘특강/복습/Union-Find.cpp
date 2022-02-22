// Union-Find 뼈대코드
// 트리로 구현

#include <iostream>
#include <vector>

using namespace std;

int parent[];

int find(int x) {
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    parent[y] = x;

    /**
     * x와 y의 루트 노드가 같다면 같은 집합이므로 종료하고
     * 그게 아니라면 y의 부모를 x로 바꿈
     */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}