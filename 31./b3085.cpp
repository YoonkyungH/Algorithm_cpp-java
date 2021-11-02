// 사탕 게임

#include <iostream>
#include <algorithm>

using namespace std;

char board[50][50];
int N;

int check() {
    int cnt = 1; int tmp = 0;

    // 가로
    for(int i=0; i<N; i++) {
        for(int j=1; j<N; j++) {
            if(board[i][j] == board[i][j-1]) { cnt++; }
            else { cnt = 1; }

            tmp = max(tmp, cnt);
        }
        cnt = 1;
    }

    // 세로
    cnt = 1;
    for(int j=0; j<N; j++) {
        for(int i=1; i<N; i++) {
            if(board[i][j] == board[i-1][j]) { cnt++; }
            else { cnt = 1; }

            tmp = max(tmp, cnt);
        }
        cnt = 1;
    }

    return tmp;
}

int main () {
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(j+1 < N) {    // 가로, 범위 벗어나지 않으면
                swap(board[i][j], board[i][j+1]);

                // int cnt = check();
                ans = max(ans, check());

                swap(board[i][j], board[i][j+1]);   // 원상복구
            }

            if(i+1 < N) {    // 가로, 범위 벗어나지 않으면
                swap(board[i][j], board[i+1][j]);

                ans = max(ans, check());

                swap(board[i][j], board[i+1][j]);   // 원상복구
            }
        }
    }

    cout << ans << '\n';

    return 0;
}