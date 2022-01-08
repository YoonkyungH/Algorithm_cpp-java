// 카드 놓기
// 순열

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int n, k;
int card[10];
bool visited[10];

set<string> s;

void backtracking(int idx, string str) {
    if(idx == k) {
        s.insert(str); return;
    }
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            backtracking(idx+1, str+to_string(card[i]));
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;

    int cnt = 0;    // 카드의 종류
    for(int i=0; i<n; i++) {
        cin >> card[i];
    }

    backtracking(0, "");

    cout << s.size() << '\n';

    return 0;
}