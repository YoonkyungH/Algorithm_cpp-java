// 지구 온난화

#include <iostream>

using namespace std;

char arr[12][12];
char ans[12][12];
int R, C;

bool check(int y, int x) {
    int cnt = 0;
    if(arr[y-1][x] == '.') {
        cnt++;
    }
    if(arr[y+1][x] == '.') {
        cnt++;
    }
    if(arr[y][x-1] == '.') {
        cnt++;
    }
    if(arr[y][x+1] == '.') {
        cnt++;
    }

    if(cnt >= 3) { return true; }
    return false;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> R >> C;

    for(int i=0; i<=R+1; i++) {   // 초기화
        for(int j=0; j<=C+1; j++) {
            arr[i][j] = '.'; ans[i][j] = '.';
        }
    }

    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];
        }
    }

    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(arr[i][j] == 'X') {
                if(check(i, j)) {   // 바다로
                    ans[i][j] = '.';
                }
            }
        }
    }


    int xxmin = 13, xxmax = 0, yymin = 13, yymax = 0; // 인덱스 찾기
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(ans[i][j] == 'X') {
                xxmin = min(xxmin, j);
                xxmax = max(xxmax, j);
                yymin = min(yymin, i);
                yymax = max(yymin, i);
            } else { continue; }
        }
    }

    for(int i=yymin; i<=yymax; i++) {
        for(int j=xxmin; j<=xxmax; j++) {
            if(ans[i][j] == 'X') {
                cout << 'X';
            } else { cout << '.'; }
        } cout << '\n';
    }


    return 0;
}