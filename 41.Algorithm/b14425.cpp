// 문자열 집합
// 중복을 허용하지 않는 map 사용
#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
int ans;
map<string, bool> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    string str;
    for(int i=0; i<N; i++) {
        cin >> str;
        m.insert(make_pair(str, true));
    }
    for(int i=0; i<M; i++) {
        cin >> str;
        if(m[str] == true) {
            ans++;
        }
    }


    cout << ans << '\n';

    return 0;
}