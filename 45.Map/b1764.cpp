// 듣보잡
#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, M;   // 듣도 못한, 보도 못한
set<string> d;
// set<string> b;
set<string> db;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;

        d.insert(str);
    }

    for(int i=0; i<M; i++) {
        string str;
        cin >> str;

        // b.insert(str);

        if(d.find(str) != d.end()) {
            db.insert(str);
        }
    }

    set<string>::iterator iter;

    cout << db.size() << '\n';
    for(iter=db.begin(); iter!=db.end(); iter++) {
        cout << *iter << '\n';
    }

    return 0;
}