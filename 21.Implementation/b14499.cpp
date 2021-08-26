#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 주사위 굴리기
// 주사위 구현만 구글링 ...

#define MAX 21

vector<int> dice(7);        // 1-6, 4-3, 2-5
int map[MAX][MAX] = {0, };  // 지도

int N, M;               // 세로, 가로
int x, y;               // 주사위 좌표

bool flag = true;       // 명령이 가능한 명령인지 (가능: true, 불가능: flase)

// 파라미터는 현재 주사위의 위치 (즉, 명령 수행 전)
void east(int yy, int xx) {   // 동
    if(xx+1 >= M) { flag = false; return; }    // 범위 미스
    // else { x++; }
    x++;

    int cv[7];
    // copy(dice.begin(), dice.end(), cv.begin());
    for(int i=1; i<=6; i++) {
        cv[i] = dice[i];
    }

    dice[1] = cv[4]; dice[2] = cv[2]; dice[3] = cv[1];
    dice[5] = cv[6]; dice[6] = cv[5]; dice[6] = cv[3];
    // dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};

}

void west(int yy, int xx) {   // 서
    if(xx-1 < 0) { flag = false; return; }
    // else { x--; }
    x--;

    int cv[7];
    // copy(dice.begin(), dice.end(), cv.begin());
    for(int i=1; i<=6; i++) {
        cv[i] = dice[i];
    }

    dice[1] = cv[3]; dice[2] = cv[2]; dice[3] = cv[6];
    dice[4] = cv[1]; dice[5] = cv[5]; dice[6] = cv[4];

    // dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};

}

void north(int yy, int xx) {  // 북
    if(yy-1 < 0) { flag = false; return; }
    // else { y--; }
    y--;

    int cv[7];
    // copy(dice.begin(), dice.end(), cv.begin());

    for(int i=1; i<=6; i++) {
        cv[i] = dice[i];
    }

    dice[1] = cv[5]; dice[2] = cv[1]; dice[3] = cv[3];
    dice[4] = cv[4]; dice[5] = cv[6]; dice[6] = cv[2];

    // dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};

}

void south(int yy, int xx) {  // 남
    if(yy+1 >= N) { flag = false; return; }
    // else { y++; }
    y++;

    int cv[7];
    // copy(dice.begin(), dice.end(), cv.begin());

    for(int i=1; i<=6; i++) {
        cv[i] = dice[i];
    }

    dice[1] = cv[2]; dice[2] = cv[6]; dice[3] = cv[3];
    dice[4] = cv[4]; dice[5] = cv[1]; dice[6] = cv[5];

    // dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};

}

int main() {
    ios::sync_with_stdio(0);

    int K;      // 명령의 개수

    cin >> N >> M >> x >> y >> K;

    for(int i=0; i<N; i++) {    // 북->남, 서->동

        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }

    }

    // 1: 동 2: 서 3: 남 4: 북
    vector<int> v;  // 명령
    for(int i=0; i<K; i++) {
        int k;
        cin >> k;

        v.push_back(k);
    }

    
    // 이동 명령 수행
    for(int i=0; i<K; i++) {
        flag = true;

        if(v[i] == 1) { east(y, x); }
        else if(v[i] == 2) { west(y, x); }
        else if(v[i] == 3) { north(y, x); }
        else if(v[i] == 4) { south(y, x); }

        if(flag == false) { continue; }

        cout << dice[1] << '\n';

        if(map[y][x] == 0) { map[y][x] = dice[6]; }
        else { dice[6] = map[y][x]; map[y][x] = 0; }
    }

    return 0;
}