// 사탕 게임

#include <iostream>
#include <algorithm>

using namespace std;

char tmp;
char board[50][50];

bool checkRow(int i, int j, char c) {   // 수평
    if(board[i-1][j] == tmp || board[i+1][j] == tmp) {
        return true;
    } 

    return false;
}

bool checkCol(int i, int j, char c) {   // 세로
    if(board[i][j-1] == tmp || board[i][j+1] == tmp) {
        return true;
    } 

    return false;
}

int main() {
    ios::sync_with_stdio(0);

    int N;  // 보드의 크기
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    tmp = board[0][0];
    int ans = 0;
    int cnt = 1;
    bool flag = false;
    
    // 가로
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i == 0 && j == 0) { continue; }

            if(flag == true) {
                tmp = board[i][j]; cnt = 1; flag = false;
            } else {
                if(board[i][j] == tmp) {
                    cnt++;
                    ans = max(cnt, ans);
                    cout << "==tmp\n";
                    cout << "ROW count: " << cnt << " i: " << i << " j: " << j << " ans= " << ans << '\n';
                    continue;
                    }
                else {
                    if(checkRow(i, j, tmp)) {
                        cnt++;
                        ans = max(cnt, ans);
                        cout << "check\n";
                        cout << "ROW count: " << cnt << " i: " << i << " j: " << j << " ans= " << ans << '\n';
                        // flag = true;
                    }
                }   
            }

            

            // if(board[i][j] == tmp) {
            //     cnt++;
            //     if(i == N-1) { cnt++; ans = max(cnt, ans); }
            //     if(checkRow(i+1, j+1, tmp)) {
            //         cnt++;
            //         ans = max(cnt, ans);
            //         cout << "ROW count: " << cnt << " i: " << i << " j: " << j << " ans= " << ans << '\n';
            //     }
            // }
            // else {  // 다른 문자가 나왔다면
            //     tmp = board[i][j];
            //     cnt = 1;
            //     continue;
            // }

        }
        flag = true;
        // tmp = board[i+1][0]; cnt = 1;
    }


    // 세로
    tmp = board[0][0];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i == 0 && j == 0) { continue; }

            if(flag == true) {
                tmp = board[j][i]; cnt = 1; flag = false;
            } else {
                if(board[j][i] == tmp) {
                    cnt++;
                    ans = max(cnt, ans);
                    cout << "==tmp\n";
                    cout << "ROW count: " << cnt << " i: " << i << " j: " << j << " ans= " << ans << '\n';
                    continue;
                }
                else {
                    if(checkRow(j, i, tmp)) {
                        cnt++;
                        ans = max(cnt, ans);
                        cout << "check\n";
                        cout << "ROW count: " << cnt << " i: " << i << " j: " << j << " ans= " << ans << '\n';
                        // flag = true;
                    }
                }   
            }

            

            // if(board[i][j] == tmp) {
            //     cnt++;
            //     if(i == N-1) { cnt++; ans = max(cnt, ans); }
            //     if(checkRow(i+1, j+1, tmp)) {
            //         cnt++;
            //         ans = max(cnt, ans);
            //         cout << "ROW count: " << cnt << " i: " << i << " j: " << j << " ans= " << ans << '\n';
            //     }
            // }
            // else {  // 다른 문자가 나왔다면
            //     tmp = board[i][j];
            //     cnt = 1;
            //     continue;
            // }

        }
        flag = true;
        // tmp = board[i+1][0]; cnt = 1;
    }

    // 세로
    // tmp = board[0][0];
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++) {
    //         if(i == 0 && j == 0) { continue; }

    //         if(board[j][i] == tmp) {
    //             cnt++;
    //             if(j == N-1) { cnt++; ans = max(cnt, ans); }
    //             if(checkCol(j+1, i+1, tmp)) {
    //                 cnt++;
    //                 ans = max(cnt, ans);
    //                 cout << "COL count: " << cnt << " i: " << i << " j: " << j << " ans= " << ans << '\n';
    //             }
    //         }
    //         else {  // 다른 문자가 나왔다면
    //             tmp = board[i][j];
    //             continue;
    //         }

    //     }
    //     tmp = board[0][i+1];
    //     cnt = 0;
    // }

    cout << ans << '\n';

    return 0;
}