// 집합
// 구현

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 21;

bool visited[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M;
    cin >> M;

    for(int i=0; i<M; i++) {
        int x;
        string s;

        cin >> s;

        if(s == "add") {
            cin >> x;
            visited[x] = true;
        } else if(s == "remove") {
            cin >> x;
            visited[x] = false;
        } else if(s == "check") {
            cin >> x;

            if(visited[x] == true) { cout << 1 << "\n"; }
            else { cout << 0 << "\n"; }
        } else if(s == "toggle") {
            cin >> x;

            if(visited[x] == true) { visited[x] = false; }
            else { visited[x] = true; }
        } else if(s == "all") {
            memset(visited, true, sizeof(visited));
        } else {
            memset(visited, false, sizeof(visited));
        }
    }

    return 0;
}