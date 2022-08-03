// 대칭 차집합
#include <iostream>
#include <map>
#include <set>
using namespace std;

int a, b;
map<int, bool> A;
map<int, bool> B;
set<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    for(int i=0; i<a; i++) {
        int n;
        cin >> n;

        A.insert(make_pair(n, true));
    }

    for(int i=0; i<b; i++) {
        int n;
        cin >> n;

        B.insert(make_pair(n, true));

        if(A.find(n) == A.end()) {
            S.insert(n);
        }
    }

    map<int, bool>::iterator iter;
    for(iter = A.begin(); iter != A.end(); iter++) {
        if(B.find(iter->first) == B.end()) {
            S.insert(iter->first);
        }
    }

    cout << S.size() << '\n';
    
    return 0;
}