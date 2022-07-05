// N-Queen
#include <iostream>
#include <cmath>
using namespace std;

int map[15];
int N;
int ans;

bool check(int level) {
    for(int i=0; i<level; i++) {
        // 대각선: 절댓값(현재 배치한 퀸의 열 - 배치된 퀸의 열) == (현재 배치한 퀸의 행 - 배치된 퀸의 행)
        if(map[i] == map[level] || abs(map[level]-map[i]) == level-i) {
            return false;
        }

    }

    return true;
}

void backtracking(int x) {
    if(x == N) {
        ans++;
    } else {
        for(int i=0; i<N; i++) {
            map[x] = i; // 퀸 배치

            if(check(x)) backtracking(x+1);
        }
    }
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    backtracking(0);

    cout << ans << '\n';

    return 0;
}