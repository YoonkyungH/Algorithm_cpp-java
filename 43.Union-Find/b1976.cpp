// 여행 가자
#include <iostream>
using namespace std;

int N, M;
int parent[200];

void init() {
    for(int i=0; i<=N; i++) {
        parent[i] = i;
    }
}

int find(int a) {
    if(parent[a] == a) return a;
    else {
        return parent[a] = find(parent[a]);
    }
}   

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return;
    else {
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;

    init();

    int a;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> a;
            
            if(a == 1) {
                Union(j, i);
            }
        }
    }

    int pre, cur;
    cin >> pre;
    pre = find(pre);
    for(int i=1; i<M; i++) {
        cin >> cur;

        if(find(cur) == find(pre)) {
            pre = cur;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}