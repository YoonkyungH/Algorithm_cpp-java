// 집합의 표현
#include <iostream>
using namespace std;

int n, m;
int parent[1000000];

void init() {
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
}

int find(int a) {
    if(parent[a] == a) return a;
    else {
        return parent[a] = find(parent[a]);
    }
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return true;
    else {
        parent[a] = b;
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    init();

    int c, a, b;
    for(int i=0; i<m; i++) {
        cin >> c >> a >> b;

        if(c == 0) {
            Union(a, b);
        } else if(c == 1) {
            if(find(a) == find(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }


    return 0;
}