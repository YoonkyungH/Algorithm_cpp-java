// 사이클 게임
#include <iostream>
using namespace std;

int n, m;
int ans;
int parent[500000];

void init() {
   for(int i=0; i<n; i++) {
        parent[i] = i;
   } 
}

int find(int a) {
    if(parent[a] == a) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) {
        return true;
    } else {
        parent[a] = b;
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    init(); // 초기화

    int a, b;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        if(Union(a, b)) {
            ans = i;
            break;
        }
    }

    if(ans == 0) {
        cout << "0\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}